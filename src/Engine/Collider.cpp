#include "Collider.h"

#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "PhysicsEngine.h"

namespace HGE
{
	bool Collider::IsColliding()	
	{
		if (currentColliders.size() > 0) { return true; }
		else { return false; }
	}

	std::vector<CollisionEvent> Collider::GetAllRigidbodyCollisions()
	{
		GetCore()->Physics->Update();

		std::vector<CollisionEvent> rtrn;

		for (int i = 0; i < currentColliders.size(); i++)
		{
			if (currentColliders.at(i).DetectedCollider.lock()->CanInteractWithRigidbodies)
			{
				rtrn.push_back(currentColliders.at(i));
			}
		}

		return rtrn;
	}

	std::vector<CollisionEvent> Collider::GetAllCollisions() 
	{ 
		return currentColliders; 
	}

	void Collider::onCreate()
	{
		transform = GetEntity()->GetTransform();
	}
}