#include "PlayerController.h"

#include <iostream>

void PlayerController::onUpdate()
{
	Keys keys;
	vec3 direciton = vec3(0, 0, 0);
	vec3 currentPos = GetEntity()->GetTransform()->GetPosition();
	if (GetCore()->Input->GetKeyDown(keys.W) && currentPos.y < extents)
	{
		direciton.y += PlayerSpeed * GetCore()->Environment->GetDeltaTime();
	}
	if (GetCore()->Input->GetKeyDown(keys.S) && currentPos.y > -extents)
	{
		direciton.y -= PlayerSpeed * GetCore()->Environment->GetDeltaTime();
	}
	if (GetCore()->Input->GetKeyDown(keys.FUNC_ESCAPE))
	{
		GetCore()->StopEngine();
	}
	
	vec3 newPos = currentPos + direciton;

	GetEntity()->GetTransform()->SetPosition(newPos);


}

void PlayerController::Reset()
{
	GetEntity()->GetTransform()->SetPosition(-6.5f, 0, -8);
}

