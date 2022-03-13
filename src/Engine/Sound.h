#include "Resource.h"

#include "al.h"
#include "alc.h"

#include <vector>

namespace HGE
{
	/*! \brief Stores Sound resources
	*
	* The Sound Structure, derived from Resource, stores and loads sounds from  
	*/
	struct Sound : Resource
	{
		friend struct AudioPlayer;
	public:
		//! Loads a .ogg file, given a file path (const string&)
		void Load(const std::string& _path);
		//! Stores the audio ID for the Sound
		ALuint ID;

	private:
		
		std::vector<char> bufferData;

		ALenum format;
		ALsizei frequency;

		void rename(std::string _path);
	};
}