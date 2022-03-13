#include "PhysicsEngine.h"

#include "Collider.h"
#include "BoxCollider.h"
#include "SphereCollider.h"


namespace HGE
{
	std::shared_ptr<PhysicsEngine> PhysicsEngine::Initialize()
	{
		std::shared_ptr<PhysicsEngine> rtrn = std::make_shared<PhysicsEngine>();
		return rtrn;
	}

	void PhysicsEngine::Update()
	{
		
		for (int i = 0; i < boxcolliders.size(); i++)
		{
			std::vector<CollisionEvent> events;
			for (int bx = 0; bx < boxcolliders.size(); bx++)
			{
				if (i != bx)
				{
					CollisionEvent tmp = boxcolliders.at(i).lock()->checkCollisionWithBox(boxcolliders.at(bx).lock());
					if (tmp.CollisionOccured) { events.push_back(tmp); }

				}
			}
			for (int sp = 0; sp < sphereColliders.size(); sp++)
			{
				CollisionEvent tmp = boxcolliders.at(i).lock()->checkCollisionWithSphere(sphereColliders.at(sp).lock());
				if (tmp.CollisionOccured) { events.push_back(tmp); }
			}
			boxcolliders.at(i).lock()->currentColliders = events;
		}

		for (int i = 0; i < sphereColliders.size(); i++)
		{
			std::vector<CollisionEvent> events;
			for (int sp = 0; sp < sphereColliders.size(); sp++)
			{
				if (i != sp)
				{
					CollisionEvent tmp = sphereColliders.at(i).lock()->checkCollisionWithSphere(sphereColliders.at(sp).lock());
					if (tmp.CollisionOccured) { events.push_back(tmp); }
				}
			}
			for (int bx = 0; bx < boxcolliders.size(); bx++)
			{
				CollisionEvent tmp = sphereColliders.at(i).lock()->checkCollisionWithBox(boxcolliders.at(bx).lock());
				if (tmp.CollisionOccured) { events.push_back(tmp); }
			}
			sphereColliders.at(i).lock()->currentColliders = events;
		}
			
	}
}