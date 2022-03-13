#include "Game/Spinner.h"

#include "engine/HGE.h"

void spinner::onUpdate()
{
	HGE::Keys keys;
	if (GetCore()->Input->GetKeyDown(keys.F))
	{
		GetEntity()->GetComponent<HGE::AudioPlayer>()->Play();
	}
	
}