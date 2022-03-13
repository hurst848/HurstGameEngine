#include "BoxCollider.h"

#include "Transform.h"
#include "SphereCollider.h"
#include "Core.h"
#include "PhysicsEngine.h"
#include "Entity.h"

namespace HGE
{
	void BoxCollider::SetHalfExtents(vec3 _halfExtents)
	{
		halfExtents = _halfExtents;
	}

	CollisionEvent BoxCollider::checkCollisionWithSphere(std::shared_ptr<SphereCollider> _collider)
	{
		CollisionEvent rtrn;

		vec3 locA = transform.lock()->GetPosition();
		vec3 dimA = halfExtents;

		vec3 locB = _collider->transform.lock()->GetPosition();
		float radius = _collider->radius;

		if (locA.x < locB.x)
		{
			if (locA.x + dimA.x < locB.x)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}
		else
		{
			if (locB.x + radius < locA.x)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}

		if (locA.y < locB.y)
		{
			if (locA.y + dimA.y < locB.y)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}
		else
		{
			if (locB.y + radius < locA.y)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}

		if (locA.z < locB.z)
		{
			if (locA.z + dimA.z < locB.z)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}
		else
		{
			if (locB.z + radius < locA.z)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}

		rtrn.CollisionOccured = true;
		rtrn.DetectedCollider = _collider;

		return rtrn;
	}
	CollisionEvent BoxCollider::checkCollisionWithBox(std::shared_ptr<BoxCollider> _collider)
	{
		CollisionEvent rtrn;

		vec3 locA = transform.lock()->GetPosition();
		vec3 dimA = halfExtents;

		vec3 locB = _collider->transform.lock()->GetPosition();
		vec3 dimB = _collider->halfExtents;
		
		if (locA.x < locB.x)
		{
			if (locA.x + dimA.x < locB.x)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}
		else
		{
			if (locB.x + dimB.x < locA.x)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}

		if (locA.y < locB.y)
		{
			if (locA.y + dimA.y < locB.y)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}
		else
		{
			if (locB.y + dimB.y < locA.y)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}

		if (locA.z < locB.z)
		{
			if (locA.z + dimA.z < locB.z)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}
		else
		{
			if (locB.z + dimB.z < locA.z)
			{
				rtrn.CollisionOccured = false;
				return rtrn;
			}
		}

		rtrn.CollisionOccured = true;
		rtrn.DetectedCollider = _collider;

		return rtrn;
	}

	void BoxCollider::RegisterCollider(std::shared_ptr<BoxCollider> _box)
	{
		GetCore()->Physics->boxcolliders.push_back(_box);
	}


}