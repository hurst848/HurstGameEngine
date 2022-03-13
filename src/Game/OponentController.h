#include "Engine/HGE.h"

using namespace HGE;

struct OpponentController : Component
{
public:
	float extents = 20;

	int OpponentSpeed = 1;
	void onUpdate();
	std::weak_ptr<Entity> ball;
	std::weak_ptr<AudioPlayer> player;
	void Reset();
};