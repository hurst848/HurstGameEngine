#include "Core.h"

#include "Entity.h"
#include "Screen.h"
#include "Assets.h"
#include "Transform.h"
#include "Input.h"
#include "Environment.h"
#include "PhysicsEngine.h"
#include "AudioManager.h"

namespace HGE
{
	std::shared_ptr<Core> Core::Initialize()
	{
		std::shared_ptr<Core> rtrn = std::make_shared<Core>();

		rtrn->Self = rtrn;
		rtrn->screen = std::make_shared<Screen>();
		rtrn->Resources = rtrn->Resources->Initialize();
		rtrn->Input = std::make_shared<Inputs>();
		rtrn->Environment = GameEnvironment().Initialize();
		rtrn->Physics = PhysicsEngine().Initialize();
		rtrn->Audio = std::make_shared<AudioManager>();
		return rtrn;
	}

	void Core::StartEngine()
	{
		
		for (int i = 0; i < entities.size(); i++)
		{
			entities.at(i)->onStart();
		}

		while (running)
		{
			int width, height;
			SDL_GetWindowSize(screen->window, &width, &height);
			glViewport(0, 0, width, height);

			glClearColor(0.584313725f, 0.784313725f, 0.847058824f, 1.0f);
			//glClearColor(0, 0, 0, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			std::vector<int> markedForRemoval;

			Environment->Update();

			Input->Update();
			Physics->Update();

			for (int i = 0; i < entities.size(); i++)
			{
				entities.at(i)->onUpdate();
				if (entities.at(i)->toBeDeleted) { markedForRemoval.push_back(i); }
			}

			for (int i = 0; i < entities.size(); i++)
			{
				entities.at(i)->onRender();
			}

			for (int i = 0; i < entities.size(); i++)
			{
				entities.at(i)->onPostRender();
			}

			SDL_GL_SwapWindow(screen->window);

			if (markedForRemoval.size() > 0)
			{
				std::vector<std::shared_ptr<Entity>> newEntities;
				for (int i = 0; i < entities.size(); i++)
				{
					bool keep = true;
					for (int j = 0; j < markedForRemoval.size(); j++)
					{
						if (i == markedForRemoval.at(j))
						{ 
							keep = false;
						}
					}
					if (keep)
					{
						newEntities.push_back(entities.at(i));
					}
				}
				entities = newEntities;
			}
		}

	}
	void Core::StopEngine()
	{
		running = false;
	}

	std::shared_ptr<Entity> Core::AddEntity()
	{
		std::shared_ptr<Entity> rtrn = std::make_shared<Entity>();
		rtrn->Self = rtrn;
		rtrn->core = Self;

		rtrn->transform = rtrn->AddComponent<Transform>();

		entities.push_back(rtrn);
		
		return rtrn;
	}
	std::shared_ptr<Entity> Core::AddEntity(std::shared_ptr<Entity> _ent)
	{
	
		
		std::shared_ptr<Entity> rtrn = std::make_shared<Entity>(*_ent);

		return rtrn;
	}

}


