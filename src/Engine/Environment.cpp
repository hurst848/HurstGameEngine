#include "Environment.h"



#include "SDL.h"

namespace HGE
{
	void GameEnvironment::Update()
	{
		// update delta time
		float currentTime = SDL_GetTicks();
		float diff = currentTime - lastTime;
		deltaTime = diff / 1000.0f;
		lastTime = currentTime;
		
	
	}

	std::shared_ptr<GameEnvironment> GameEnvironment::Initialize()
	{	
		std::shared_ptr<GameEnvironment> rtrn = std::make_shared<GameEnvironment>();
		rtrn->deltaTime = 0.0f; 
		rtrn->lastTime = 0.0f;

		
		return rtrn;
	}
	
	float GameEnvironment::GetDeltaTime(){ return deltaTime; }


}