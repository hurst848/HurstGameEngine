#include "AudioManager.h"

namespace HGE
{
	AudioManager::AudioManager()
	{
		// Create open AL device
		device = alcOpenDevice(NULL);
		if (!device)
		{
			throw std::exception();
		}
		// Create open AL context
		context = alcCreateContext(device, NULL);
		if (!context)
		{
			alcCloseDevice(device);
			throw std::exception();
		}
		// Make the context current
		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::exception();
		}
	}


	AudioManager::~AudioManager()
	{
		alcMakeContextCurrent(NULL);
		alcDestroyContext(context);
		alcCloseDevice(device);
	}
}