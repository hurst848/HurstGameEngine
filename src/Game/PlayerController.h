#include "Engine/HGE.h"

using namespace HGE;

struct PlayerController : Component
{
public:
	float extents = 20;

	int PlayerSpeed = 1;

	void onUpdate();
	void Reset();
	std::weak_ptr<AudioPlayer> player;
};