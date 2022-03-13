#include "Resource.h"

#include "Maths.h"

#include "glew.h"

namespace HGE
{
	/*! \brief Stores Texture resources
	*
	* The Texture Structure, derived from Resource, stores and loads textures from
	* .png files, and uploads them to the GPU for openGL to use 
	*/
	struct Texture : Resource
	{
	public:
		//! Loads a .png file, given a file path (const string&)
		void Load(const std::string& _path);
		//! Stores the Texture ID for the Texture
		GLuint ID;
		//! Stores the x, y size (ivec2) of the loaded texture
		ivec2 TextureSize;
	};
}