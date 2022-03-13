#include "Sound.h"
#include "misc/stb-master/stb_vorbis.c"

namespace HGE
{
	void Sound::Load(const std::string& _path)
	{
		rename(_path);

		ID = 0;
		alGenBuffers(1, &ID);

		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename
		(
			_path.c_str(),
			&channels,
			&sampleRate,
			&output
		);

		if (samples == -1) { throw std::exception(); }

		if (channels == 1) { format = AL_FORMAT_MONO16; }
		else { format = AL_FORMAT_STEREO16; }

		frequency = sampleRate;
		
		bufferData.resize(samples * 2);
		memcpy(&bufferData.at(0), output, bufferData.size());

		free(output);

		alBufferData
		(
			ID,
			format,
			&bufferData.at(0),
			static_cast<ALsizei>(bufferData.size()),
			frequency
		);

	}

	void Sound::rename(std::string _path)
	{
		while (_path.find("/") != std::string::npos)
		{
			_path = _path.substr(1);
		}
		std::string rtrn = _path.substr(0, _path.find(".")) + ".snd";
		Name = rtrn;
	}


}