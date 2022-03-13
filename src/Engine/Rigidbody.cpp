#include "Rigidbody.h"

#include "Entity.h"
#include "Transform.h"
#include "Collider.h"
#include "Core.h"
#include "Environment.h"

#include <iostream>
namespace HGE
{
	vec3 Rigidbody::GetVelocity()
	{
		return velocity;
	}
	void Rigidbody::SetVelocity(vec3 _velocity)
	{
		velocity = _velocity;
	}

	void Rigidbody::onCreate()
	{
		transform = GetEntity()->GetTransform();
		collider = GetEntity()->GetComponent<Collider>();
		velocity = vec3(0, 0, 0);

	}
	void Rigidbody::onUpdate()
	{
		std::vector<CollisionEvent> evnts = collider.lock()->GetAllRigidbodyCollisions();

		vec3 CurrentPosition = transform.lock()->GetPosition();
		if (!(evnts.size() > 0) && Gravity)
		{
			velocity.y += -9.8f * GetCore()->Environment->GetDeltaTime();
		}
		else
		{
			std::cout << evnts.size() << " RIGIDBODY COLLSION DETECTED" << std::endl;
			// Kludge Collider Test // 
			

			// left
			transform.lock()->SetPosition(
				vec3
				(
					CurrentPosition.x - 0.5f,
					CurrentPosition.y,
					CurrentPosition.z
				)
			);
			evnts = collider.lock()->GetAllRigidbodyCollisions();
			if (!(evnts.size() > 0))
			{
				transform.lock()->SetPosition(CurrentPosition);
				velocity.x = -velocity.x / 2;
			}
			else
			{
				transform.lock()->SetPosition(CurrentPosition);
				// right
				transform.lock()->SetPosition(
					vec3
					(
						CurrentPosition.x + 0.5f,
						CurrentPosition.y,
						CurrentPosition.z
					)
				);
				evnts = collider.lock()->GetAllRigidbodyCollisions();
				if (!(evnts.size() > 0))
				{
					transform.lock()->SetPosition(CurrentPosition);
					velocity.x = -velocity.x / 2;
				}
				else
				{
					// forward
					transform.lock()->SetPosition(
						vec3
						(
							CurrentPosition.x,
							CurrentPosition.y,
							CurrentPosition.z + 0.5f
						)
					);
					evnts = collider.lock()->GetAllRigidbodyCollisions();
					if (!(evnts.size() > 0))
					{
						transform.lock()->SetPosition(CurrentPosition);
						velocity.z = -velocity.z / 2;
					}
					else
					{
						// backwards
						transform.lock()->SetPosition(
							vec3
							(
								CurrentPosition.x,
								CurrentPosition.y,
								CurrentPosition.z - 0.5f
							)
						);
						evnts = collider.lock()->GetAllRigidbodyCollisions();
						if (!(evnts.size() > 0))
						{
							transform.lock()->SetPosition(CurrentPosition);
							velocity.z = -velocity.z / 2;
						}
						else
						{
							// up
							transform.lock()->SetPosition(
								vec3
								(
									CurrentPosition.x,
									CurrentPosition.y + 0.5f,
									CurrentPosition.z
								)
							);
							evnts = collider.lock()->GetAllRigidbodyCollisions();
							if (!(evnts.size() > 0))
							{
								transform.lock()->SetPosition(CurrentPosition);
								velocity.y = -velocity.y / 2;
							}
							else
							{
								// down
								transform.lock()->SetPosition(
									vec3
									(
										CurrentPosition.x,
										CurrentPosition.y - 0.5f,
										CurrentPosition.z
									)
								);
								evnts = collider.lock()->GetAllRigidbodyCollisions();
								if (!(evnts.size() > 0))
								{
									transform.lock()->SetPosition(CurrentPosition);
									velocity.y = -velocity.y / 2;
								}
							}
						}
					}
				}

			}
			
		}
		vec3 finalImpulse = CurrentPosition + (velocity * GetCore()->Environment->GetDeltaTime());
		transform.lock()->SetPosition(finalImpulse);
	}
}