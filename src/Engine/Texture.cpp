#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION

#include "misc/stb-master/stb_image.h"



namespace HGE
{
	void Texture::Load(const std::string& _path)
	{
		unsigned char* data = stbi_load
		(
			_path.c_str(), 
			&TextureSize.x, 
			&TextureSize.y, 
			NULL, 
			4
		);

		glGenTextures(1, &ID);
		if (!ID) { throw std::exception(); }
		glBindTexture(GL_TEXTURE_2D, ID);

		glTexImage2D
		(
			GL_TEXTURE_2D, 
			0, GL_RGBA, 
			TextureSize.x, 
			TextureSize.y, 0, 
			GL_RGBA,
			GL_UNSIGNED_BYTE, 
			data
		);

		free(data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE, 0);
	}
}