#include "al.h"
#include "alc.h"

#include <memory>

namespace HGE
{
	/*! \brief Is a strucure that stores the Audio Context
	*
	* The AudioManager Structure acts as a container for the ALCdevice,
	* ALCcontext and the currrent AudioListener being used
	*/
	struct AudioManager
	{
		friend struct AudioPlayer;
		friend struct AudioListener;
	public:
		//! Base constructor for AudioManager, sets up all openAL requirments (AudioManager)
		AudioManager();
		//! Destructor for AudioManager to destroy the openAL device and context
		~AudioManager();
	private:
		std::weak_ptr<AudioListener> currentListner;

		ALCdevice* device = NULL;
		ALCcontext* context = NULL;
	};
}

