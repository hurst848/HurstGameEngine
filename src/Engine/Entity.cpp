#include "Entity.h"

#include "Core.h"
#include "Component.h"
#include "Transform.h"

namespace HGE
{
	std::shared_ptr<Core> Entity::GetCore()
	{
		return core.lock();
	}


	void Entity::onCreate()
	{
		for (int i = 0; i < components.size(); i++)
		{
			components.at(i)->onCreate();
		}
	}
	void Entity::onStart()
	{
		for (int i = 0; i < components.size(); i++)
		{
			components.at(i)->onStart();
		}
	}
	void Entity::onUpdate()
	{
		for (int i = 0; i < components.size(); i++)
		{
			components.at(i)->onUpdate();
		}
	}
	void Entity::onRender()
	{
		for (int i = 0; i < components.size(); i++)
		{
			components.at(i)->onRender();
		}
	}
	void Entity::onPostRender()
	{
		for (int i = 0; i < components.size(); i++)
		{
			components.at(i)->onPostRender();
		}
	}

	std::shared_ptr<Transform> Entity::GetTransform()
	{
		return transform.lock();
	}

}


