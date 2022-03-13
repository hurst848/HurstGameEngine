#include "CameraController.h"


#include <iostream>

void CameraController::onUpdate()
{
	vec3 direction = vec3(0, 0, 0);
	HGE::Keys keys;
	HGE::MouseCharateristics mouse;
	float speed = 5;

	if (GetCore()->Input->GetKeyDown(keys.FUNC_LEFTSHIFT))
	{
		speed = 15;
	}
	if (GetCore()->Input->GetKeyDown(keys.A)) // Left
	{
		direction.x -= 1 * (speed * GetCore()->Environment->GetDeltaTime());
		//direction = GetEntity()->GetTransform()->GetForward() * speed * GetCore()->Environment->GetDeltaTime();
	}
	if (GetCore()->Input->GetKeyDown(keys.D)) // Right
	{
		direction.x += 1 * (speed * GetCore()->Environment->GetDeltaTime());
		//direction = GetEntity()->GetTransform()->GetForward() * -speed * GetCore()->Environment->GetDeltaTime();
	}
	if (GetCore()->Input->GetKeyDown(keys.S)) // Back
	{
		direction.z += 1 * (speed * GetCore()->Environment->GetDeltaTime());
	}
	if (GetCore()->Input->GetKeyDown(keys.W)) // Forward
	{
		direction.z -= 1 * (speed * GetCore()->Environment->GetDeltaTime());
	}
	if (GetCore()->Input->GetKeyDown(keys.FUNC_SPACE)) // Up
	{
		direction.y += 1 * (speed * GetCore()->Environment->GetDeltaTime());
	}
	if (GetCore()->Input->GetKeyDown(keys.FUNC_LEFTCTRL)) // Down
	{
		direction.y -= 1 * (speed * GetCore()->Environment->GetDeltaTime());
	}
	

	float xoff = -GetCore()->Input->GetMouseData(mouse.MOUSE_DELTA).x;
	float yoff = -GetCore()->Input->GetMouseData(mouse.MOUSE_DELTA).y;

	GetEntity()->GetTransform()->SetRotation(GetEntity()->GetTransform()->GetRotation() + (vec3(xoff, yoff, 0) * GetCore()->Environment->GetDeltaTime()));


	if (GetCore()->Input->GetKeyDown(keys.NUM_1))
	{
		GetCore()->Input->SetMouseMode(mouse.MOUSE_RELATIVETRUE);
	}
	else if (GetCore()->Input->GetKeyDown(keys.NUM_2))
	{
		GetCore()->Input->SetMouseMode(mouse.MOUSE_RELATIVEFALSE);
	}

	if (GetCore()->Input->GetMouseDown(mouse.MOUSE_LEFTBUTTON))
	{
		vec2 mousePos = GetCore()->Input->GetMouseData(mouse.MOUSE_LOCATION);
	}
	

	GetEntity()->GetTransform()->SetPosition(GetEntity()->GetTransform()->GetPosition() + direction);

	std::shared_ptr<HGE::SphereCollider> collider = GetEntity()->GetComponent<HGE::SphereCollider>();

	

	if (collider->IsColliding())
	{
		std::cout << "IM COLLIDING WITH SHIT" << std::endl;
	}
}