#include "Engine/HGE.h"

using namespace HGE;


struct BallController : Component
{
public:
	float BallSpeed = 2.0f;


	void onUpdate();

	float extents;

	std::weak_ptr<SphereCollider> collider;
	std::weak_ptr<AudioPlayer> player;

	std::weak_ptr<AudioPlayer> opp;
	std::weak_ptr<AudioPlayer> plyr;
private:
	vec3 startPos = vec3(0, 0, -8);
	vec3 velocity = vec3(0, 0, 0);
	bool restart = true;
	float countdownTimer = 2.0f;
};