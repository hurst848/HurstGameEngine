#include "Collider.h"
#include "Component.h"
#include "Maths.h"

namespace HGE
{
	struct SphereCollider;

	/*! \brief Is a spherical physics collider.
	*
	* The BoxCollider, child of collider, is a componet used to give entities
	* a cuboid collider to allow for collision detection
	*
	*/
	struct BoxCollider : Collider
	{
		friend struct Entity;
		friend struct PhysicsEngine;
		friend struct SphereCollider;
	public: 
		//! Sets the Box's half extent value, given a width, height and depth (vec3)
		void SetHalfExtents(vec3 _halfExtents);
		//! Registers the collider with the physics engine so that is is simulated, given a shared pointer to self (shared_ptr<BoxCollider>)
		void RegisterCollider(std::shared_ptr<BoxCollider> _box);
	private:
		CollisionEvent checkCollisionWithSphere(std::shared_ptr<SphereCollider> _collider);
		CollisionEvent checkCollisionWithBox(std::shared_ptr<BoxCollider> _collider);

		vec3 halfExtents;



	};
}