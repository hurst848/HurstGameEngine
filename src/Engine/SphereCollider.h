#include "Collider.h"
#include "Component.h"
#include "Maths.h"

namespace HGE
{
	struct BoxCollider;
	/*! \brief Is a spherical physics collider.
	*
	* The SphereCollider, child of collider, is a componet used to give entities
	* a spherical collider to allow for collision detection
	*
	*/
	struct SphereCollider : Collider
	{
		friend struct Entity;
		friend struct PhysicsEngine;
		friend struct BoxCollider;
	public:
		//! Sets the Sphere's radius value, given a width, height and depth (vec3)
		void SetRadius(float _radius);
		//! Registers the collider with the physics engine so that is is simulated, given a shared pointer to self (shared_ptr<SphereCollider>)
		void RegisterCollider(std::shared_ptr<SphereCollider> _sphere);
	private:
		CollisionEvent checkCollisionWithSphere(std::shared_ptr<SphereCollider> _collider);
		CollisionEvent checkCollisionWithBox(std::shared_ptr<BoxCollider> _collider);

		float radius;
	};
}