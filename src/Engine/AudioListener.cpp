#include "AudioListener.h"

#include "Core.h"
#include "Entity.h"
#include "AudioManager.h"

namespace HGE
{
	void AudioListener::SetActiveListner()
	{
		GetCore()->Audio->currentListner = as.lock();
	}

	void AudioListener::onCreate()
	{
		transform = GetEntity()->GetTransform();
	}

	void AudioListener::SetSelf(std::shared_ptr<AudioListener> _self)
	{
		as = _self;
	}
}