#include "Component.h"

#include "Maths.h"

namespace HGE
{
	/*! \brief Stores all transformational data
	*
	* The Transform Structure is a component used to store all positional, rotational and
	* scaling data. Is also where the model matrix is generated. Every created Entity structure is
	* created with a Transform by default, unless manually removed
	*/
	struct Transform : Component
	{
	public:
		//! Base constructor for Transform, defaults position and rotation to vec3(0) and scale to vec3(1) (Transform)
		Transform();
		//! Calculates and returns the a model matrix used in the ShaderProgram (mat4)
		mat4 GetModelMatrix();
		//! Sets the parent Transfom of this Transrom, give a shared pointer to a Transform (shared_ptr<Transform>)
		void SetParent(std::shared_ptr<Transform> _parent);
		//! Return the current position of the Transform (vec3)
		vec3 GetPosition();
		//! Return the current rotation of the Transform (vec3)
		vec3 GetRotation();
		//! Return the current scale of the Transform (vec3)
		vec3 GetScale();
		//! Return the current forward vector of the Transform (vec3)
		vec3 GetForward();

		//! Sets the position of the Transform, given an x, y and z value (float)
		void SetPosition(float _x, float _y, float _z);
		//! Sets the position of the Transform, given an vector (vec3)
		void SetPosition(vec3 _pos);
		//! Sets the rotation of the Transform, given an x, y and z value (float)
		void SetRotation(float _x, float _y, float _z);
		//! Sets the rotation of the Transform, given an vector (vec3)
		void SetRotation(vec3 _rot);
		//! Sets the scale of the Transform, given an x, y and z value (float)
		void SetScale(float _x, float _y, float _z);
		//! Sets the scale of the Transform, given an vector (vec3)
		void SetScale(vec3 _scl);

	private:

		vec3 position;
		vec3 rotation;
		vec3 scale;
		vec3 forward;

		std::weak_ptr<Transform> parent; 
	};
}

