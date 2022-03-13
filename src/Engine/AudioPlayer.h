#include "Component.h"

#include <memory>

namespace HGE
{

	struct Sound;
	struct Transform;
	struct AudioManager;
	/*! \brief Is a a positional audio player
	*
	* The AudioPlayer, is a component used to allow entities
	* to playback audio or sounds within 3D space, for the AudioListener to hear.
	*
	*/
	struct AudioPlayer : Component
	{
		friend struct Entity;
	public:
		//! Sets the current sound clip of the audio player, given a Sound resource (shared_ptr<Sound>)
		void SetSoundClip(std::shared_ptr<Sound> _sound);
		//! Plays the current Sound
		void Play();

	private:
		std::shared_ptr<Sound> currentClip;
		std::weak_ptr<Transform> transfom;
		std::weak_ptr<AudioManager> audioManager;

	protected:
		// Called when created, binds the refences of transform and the AudioManager
		void onCreate();
	};
}
