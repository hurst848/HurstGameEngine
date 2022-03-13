#include "AudioPlayer.h"

#include "Core.h"
#include "Entity.h"
#include "AudioManager.h"
#include "AudioListener.h"
#include "Sound.h"
#include "Maths.h"
#include "Transform.h"

#include "al.h"
#include "alc.h"

namespace HGE
{
	void AudioPlayer::SetSoundClip(std::shared_ptr<Sound> _sound)
	{
		currentClip = _sound;
	}

	void AudioPlayer::Play()
	{
		// only play if a clip is attached
		if (currentClip != NULL)
		{
			vec3 listnerPos = audioManager.lock()->currentListner.lock()->transform.lock()->GetPosition();
			vec3 playerPos = transfom.lock()->GetPosition();

			ALuint sid = 0;
			alGenSources(1, &sid);
			// Only attempt positional audio if the audiomanager has a listener assigned
			if (GetCore()->Audio->currentListner.lock())
			{

				alListener3f(AL_POSITION, listnerPos.x, listnerPos.y, listnerPos.z);
				alSource3f(sid, AL_POSITION, playerPos.x, playerPos.y, playerPos.z);
				
			}
			alSourcei(sid, AL_BUFFER, currentClip->ID);
			alSourcePlay(sid);
		}
	}

	void AudioPlayer::onCreate()
	{
		transfom = GetEntity()->GetTransform();
		audioManager = GetCore()->Audio;
	}
}