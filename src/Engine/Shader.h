#include "Resource.h"

#include "glew.h"

#include <vector>
#include <memory>
#include <string>

namespace HGE
{
	/*! \brief Stores the shader resources 
	*
	* The Shader Structure, derived from Resource, takes a valid .vert or
	* .frag file and parses it for use in the ShaderProgram. Uniform and Attribute flags
	* are also parsed here, details of what each flag is and is correponing varible can be found bellow: \n
	* fa-1 = attribute vec3 a_Position \n
	* fa-2 = attribute vec2 a_TextureCoordinates \n
	* fa-3 = attribute vec3 a_Normal \n
	* fu-1 = uniform mat4 u_ModelMatrix \n
	* fu-2 = uniform mat4 u_ProjectionMatrix \n
	* fu-3 = uniform mat4 u_ViewMatrix \n
	* fu-4 = uniform vec3 u_LightColour \n
	* fu-5 = uniform vec3 u_LightPosition \n
	* fu-6 = uniform float u_LightAmbientStrength \n
	* fu-7 = unifrom sampler2D u_Texture \n\n\n
	* 
	* Addtionally, the format of the top of each shader file should start with "//~" and must
	* be space apart with commas. Example shown bellow: \n
	* "//~ fu-4, fu-5, fu-6"
	*/
	struct Shader : Resource
	{
		friend struct ShaderProgram;

	public:
		//! Loads a .vert or .frag file, given a file path (const string&)
		void Load(const std::string& _path);
		//! Destructor for Screen to destroy the shader code
		~Shader();
		//! Stores the shader ID for the ShaderProgram
		GLuint ID;

	private:

		const GLchar* code;

		std::vector<std::string> flags;

		void evaluateFlags(std::string _line);

		/*
		* FLAGS:
		* 
		*	fa-1 = attribute vec3 a_Position
		*	fa-2 = attribute vec2 a_TextureCoordinates
		*	fa-3 = attribute vec3 a_Normal
		*	
		*	fu-1 = uniform mat4 u_ModelMatrix
		*	fu-2 = uniform mat4 u_ProjectionMatrix
		*	fu-3 = uniform mat4 u_ViewMatrix
		*	fu-4 = uniform vec3 u_LightColour
		*	fu-5 = uniform vec3 u_LightPosition
		*	fu-6 = uniform float u_LightAmbientStrength
		*	fu-7 = unifrom sampler2D u_Texture
		*/
	};

	/*! \brief Stores a ShaderProgram used for rendering
	*
	* The ShaderProgram Structure takes a vertex Shader and a fragement Shader, and
	* creates a ShaderProgram for the GPU to render, used by the MeshRenderer.
	*/
	struct ShaderProgram
	{
		friend struct MeshRenderer;
	public:
		//! Stores the ShaderProgram ID for redering
		GLuint ID;
		//! Adds a Shader Resource to the ShaderProgram to be compiled, given a shared pointer to a Shader (shared_ptr<Shader>)
		void AddShader(std::shared_ptr<Shader> _shader);
		//! Comiles all shaders added by the AddShader function to create a ShaderProgram 
		void Compile();

	private:
		std::vector<std::shared_ptr<Shader>> shaders;

		struct ShaderUniform
		{
			std::string name;
			GLuint ID;
		};

		std::vector<ShaderUniform> uniforms;
	};
	
}