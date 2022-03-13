#ifndef _COLLIDER_H_
#define _COLLIDER_H_

#include "Component.h"

#include "Maths.h"

#include <memory>
#include <vector>
#include <string>


namespace HGE
{
	struct Transform;
	struct Collider;
	struct CollisionEvent;
	struct SphereCollider;
	struct BoxCollider;
	/*! \brief Contains the data from a collision
	*
	* The CollisionEvent Structure holds all neccicary data from any collision
	* events that occur
	*
	*/
	struct CollisionEvent
	{
		friend struct Entity;
	public:
		//! Holds a weak pointer (weak_ptr<Collider>) to the collider that has just been collided with
		std::weak_ptr<Collider> DetectedCollider;
		//! Is the exact point where the collision occurs (vec3)
		vec3 CollisionLocation;
		//! States whether a collision has actually occured, and whether this data is actually useful (bool)
		bool CollisionOccured;
	};

	/*! \brief Is the Parent Structure to the Colliders
	*
	* The Collider structure is the parent strucure to both the BoxCollider and the
	* SphereCollider. Additonally it stores data used by both.
	*
	*/
	struct Collider : Component
	{
		friend struct PhysicsEngine;
	public:
		//! Returns true (bool) if the current collider is actually colliding.
		bool IsColliding();
		//! Returns a vector of collision enents (vector<CollisionEvent>) that can interact with rigidbodies
		std::vector<CollisionEvent> GetAllRigidbodyCollisions();
		//! Returns a vector of collision events (vector<CollisionEvent>) if and collision events are registered
		std::vector<CollisionEvent> GetAllCollisions();
		//! Stores a tag (string) for differentiation between all of the colliders
		std::string Tag;
		//! Stores whether or not the collider can interact with rigidbodies
		bool CanInteractWithRigidbodies;

	protected:
		//! A virtual function return a collision event (CollisionEvent) to be implemented by the child strucures BoxCollider and SphereColloder, given a shared pointer to a collider (shared_ptr<Collider>)
		virtual CollisionEvent checkCollisionWithSphere(std::shared_ptr<SphereCollider> _collider) { return CollisionEvent(); };
		//! A virtual function return a collision event (CollisionEvent) to be implemented by the child strucures BoxCollider and SphereColloder, given a shared pointer to a collider (shared_ptr<Collider>)
		virtual CollisionEvent checkCollisionWithBox(std::shared_ptr<BoxCollider> _collider) { return CollisionEvent(); };
		//! A weak pointer to the collier's entity's transfrom (weak_ptr<Transform>)
		std::weak_ptr<Transform> transform;
		//! A vector containing all current collision Events (vector<CollisionEvent>)
		std::vector<CollisionEvent> currentColliders;
		//! Inherited from the Component structure, used upon creation
		void onCreate();
	};
}

#endif // !_COLLIDER_H_


