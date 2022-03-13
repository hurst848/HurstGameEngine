#include "Component.h"

#include <memory>

namespace HGE
{
	struct Mesh;
	struct ShaderProgram;
	struct Texture;
	/*! \brief Renders a Mesh structure to the Screen
	*
	* The MeshRenderer Structure is a component that uses a ShaderProgram to render a Mesh to the Screen.
	*/
	struct MeshRenderer : Component
	{
	public:
		//! Specifies whether or not to render the object (bool)
		bool Render;
		//! Specifies which projection matrix to use. If true, use an orthographic matrix, if false use a perspective matrix (bool)
		bool Orthographic;
		//! Set the Mesh Resource of the MeshRenderer, given a shared pointer to a Mesh (shared_ptr<Mesh>)
		void SetMesh(std::shared_ptr<Mesh> _mesh);
		//! Set the ShaderProgram Resource of the MeshRenderer, given a shared pointer to a ShaderProgram (shared_ptr<ShaderProgram>)
		void SetShader(std::shared_ptr<ShaderProgram> _program);
		//! Set the Mesh Resource of the Texture, given a shared pointer to a Texture (shared_ptr<Texture>)
		void SetTexture(std::shared_ptr<Texture> _texture);

	private:
		void onRender();

		std::shared_ptr<Mesh> mesh;
		std::shared_ptr<ShaderProgram> program;
		std::shared_ptr<Texture> texture;
	};
}