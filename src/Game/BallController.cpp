#include "BallController.h"

#include "PlayerController.h"
#include "OponentController.h"



void BallController::onUpdate()
{
	vec3 currentPos = GetEntity()->GetTransform()->GetPosition();
	if (restart)
	{
		velocity = vec3(0);
		GetEntity()->GetTransform()->SetPosition(0, 0, -8);
		countdownTimer -= GetCore()->Environment->GetDeltaTime();
		if (countdownTimer <= 0)
		{
			countdownTimer = 2.0f;
			restart = false;
			vec3 startDir = normalize(vec3(linearRand(-100.0f, 100.0f), linearRand(-100.0f, 100.0f), 0));
			velocity = startDir * (BallSpeed * GetCore()->Environment->GetDeltaTime());
		}
	}
	else
	{
		std::vector<CollisionEvent> events = collider.lock()->GetAllCollisions();
		if (events.size() > 0)
		{
			for (int i = 0; i < events.size(); i++)
			{
				if (events.at(i).DetectedCollider.lock()->Tag == "TopLog" ||
					events.at(i).DetectedCollider.lock()->Tag == "BottomLog")
				{
					velocity.y = -velocity.y;
					
				}
				else if (events.at(i).DetectedCollider.lock()->Tag == "UserPaddle" ||
					events.at(i).DetectedCollider.lock()->Tag == "EnemyPaddle")
				{
					float randomness = normalize(vec3(linearRand(0.0f, 100.0f))).y * GetCore()->Environment->GetDeltaTime();
					if (velocity.y > 0) { velocity.y = randomness; }
					else { velocity.y += -randomness; }
					velocity.x = -velocity.x;
				}
				player.lock()->Play();
				
				
			}
		}
		else if (currentPos.x > extents ) // player wins 
		{
			plyr.lock()->Play();
			restart = true;
		}
		else if (currentPos.x < -extents) // opponent wins
		{
			opp.lock()->Play();
			restart = true;
		}
		GetEntity()->GetTransform()->SetPosition(currentPos + velocity);


	}
}