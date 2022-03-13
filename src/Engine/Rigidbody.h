#include "Component.h"

#include "Maths.h"

#include <memory>


namespace HGE
{
	struct Collider;	
	struct Transform;
	/*! \brief Allows for physics based dynamic movement
	*
	* The Rigidbody Structure is a component, that gives a Entity physics properties.
	* Requires an Collider in order to function.
	*/
	struct Rigidbody : Component
	{
		friend struct Entity;
	public:
		//! Returns the current velocity of the Rigidbody (vec3)
		vec3 GetVelocity();
		//! Sets the velocity of the current Rigidbody (vec3)
		void SetVelocity(vec3 _velocity);
		//! States whether or not gravity is active on this Rigidbody, true if enabled and false if disabled (bool)
		bool Gravity;
	private:
		void onCreate();
		void onUpdate();

		vec3 velocity;
		std::weak_ptr<Collider> collider;
		std::weak_ptr<Transform> transform;


	};

}
