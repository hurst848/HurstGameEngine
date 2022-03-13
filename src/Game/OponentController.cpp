#include "OponentController.h"


void OpponentController::onUpdate()
{
	vec3 direciton = vec3(0, 0, 0);
	vec3 currentPos = GetEntity()->GetTransform()->GetPosition();

	if (ball.lock()->GetTransform()->GetPosition().y > currentPos.y && currentPos.y < extents)
	{
		direciton.y += OpponentSpeed * GetCore()->Environment->GetDeltaTime();
	}
	else if (ball.lock()->GetTransform()->GetPosition().y < currentPos.y && currentPos.y > -extents)
	{
		direciton.y -= OpponentSpeed * GetCore()->Environment->GetDeltaTime();
	}

	vec3 newPos = currentPos + direciton;

	GetEntity()->GetTransform()->SetPosition(newPos);
}

void OpponentController::Reset()
{
	GetEntity()->GetTransform()->SetPosition(6.5f, 0, -8);
}