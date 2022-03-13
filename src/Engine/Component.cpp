#include "Component.h"
#include "Entity.h"

namespace HGE
{
	std::shared_ptr<Core> Component::GetCore()
	{
		return entity.lock()->GetCore();
	}
	std::shared_ptr<Entity> Component::GetEntity()
	{
		return entity.lock();
	}
}