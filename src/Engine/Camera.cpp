#include "Camera.h"

#include "Transform.h"
#include "Entity.h"
#include "Core.h"
#include "Environment.h"

namespace HGE
{
	mat4 Camera::GetViewMatrix()
	{
		return GetEntity()->GetTransform()->GetModelMatrix();
	}
	void Camera::SetAsMainCamera()
	{
		GetCore()->Environment->mainCamera = std::make_shared<Camera>(*this);
	}
}