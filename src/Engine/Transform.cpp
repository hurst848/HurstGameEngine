#include "Transform.h"

namespace HGE
{
	Transform::Transform()
	{
		position = vec3(0, 0, 0);
		rotation = vec3(0, 0, 0);
		scale = vec3(1, 1, 1);
	}

	mat4 Transform::GetModelMatrix()
	{
		mat4 rtrn(1.0f);

		if (!parent.expired())
		{
			std::shared_ptr<Transform> tmp = parent.lock();
			rtrn = GetModelMatrix();
		}


		rtrn = translate(rtrn, position);
		
		// remove if broken
		rtrn *= vec4(scale, 1);

		rtrn = rotate(rtrn, radians(rotation.x), vec3(0, 1, 0));
		rtrn = rotate(rtrn, radians(rotation.y), vec3(1, 0, 0));
		rtrn = rotate(rtrn, radians(rotation.z), vec3(0, 0, 1));

		forward = normalize(vec3(rtrn[2]));

		return rtrn;
	}

	vec3 Transform::GetPosition() { return position; }
	vec3 Transform::GetRotation() { return rotation; }
	vec3 Transform::GetScale() { return scale; }

	vec3 Transform::GetForward() { return forward; }

	void Transform::SetPosition(float _x, float _y, float _z) { position = vec3(_x, _y, _z); }
	void Transform::SetPosition(vec3 _pos) { position = _pos; }
	void Transform::SetRotation(float _x, float _y, float _z) { rotation = vec3(_x, _y, _z); }
	void Transform::SetRotation(vec3 _rot) { rotation = _rot; }
	void Transform::SetScale(float _x, float _y, float _z) { scale = vec3(_x, _y, _z); }
	void Transform::SetScale(vec3 _scl) { scale = _scl; }

	void Transform::SetParent(std::shared_ptr<Transform> _parent)
	{
		parent = _parent;
	}
}