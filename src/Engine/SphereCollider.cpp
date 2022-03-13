#include "SphereCollider.h"

#include "Transform.h"
#include "BoxCollider.h"
#include "Core.h"
#include "PhysicsEngine.h"
#include "Entity.h"



namespace HGE
{
	void SphereCollider::SetRadius(float _radius)
	{
		radius = _radius;
	}

	CollisionEvent SphereCollider::checkCollisionWithSphere(std::shared_ptr<SphereCollider> _collider)
	{
		CollisionEvent rtrn;
		
		vec3 locA = transform.lock()->GetPosition();
		float radiusA = radius;
		
		vec3 locB = _collider->transform.lock()->GetPosition();
		float radiusB = _collider->radius;

		if (distance(locA, locB) <= (radiusA + radiusB))
		{
			rtrn.DetectedCollider = _collider;
			rtrn.CollisionOccured = true;
		}
		else
		{
			rtrn.CollisionOccured = false;
		}

		return rtrn;
	}
	CollisionEvent SphereCollider::checkCollisionWithBox(std::shared_ptr<BoxCollider> _collider)
	{



		CollisionEvent rtrn;
		
		vec3 locA = transform.lock()->GetPosition();
		

		vec3 locB = _collider->transform.lock()->GetPosition();
		vec3 dim = _collider->halfExtents;

		if (locA.x < locB.x)
		{
			if (locA.x + radius < locB.x)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}
		else
		{
			if (locB.x + dim.x < locA.x)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}

		if (locA.y < locB.y)
		{
			if (locA.y + radius < locB.y)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}
		else
		{
			if (locB.y + dim.y < locA.y)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}

		if (locA.z < locB.z)
		{
			if (locA.z + radius < locB.z)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}
		else
		{
			if (locB.z + dim.z < locA.z)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}

		rtrn.CollisionOccured = true;
		rtrn.DetectedCollider = _collider;

		return rtrn;

		return rtrn;
	}

	void SphereCollider::RegisterCollider(std::shared_ptr<SphereCollider> _sphere)
	{
		GetCore()->Physics->sphereColliders.push_back(_sphere);
	}
}