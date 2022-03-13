#include "Resource.h"

#include "glew.h"

#include <string>

namespace HGE
{
	/*! \brief Stores Vertex Array objects that have mesh data
	*
	* The Mesh Structure, derived from Resource, creates and stores a OpenGL vertex array object,
	* to allow for rendering of the mesh file. Only .obj files are currently accepted.
	*/
	struct Mesh : Resource
	{
		friend struct MeshBuilder;

	public:
		//! Loads a .obj file, given a file path (const string&)
		void Load(const std::string& _path);
		//! Stores the vertex array object ID for rendering
		GLuint ID;
		//! Stores the vertex count of the loaded mesh
		size_t VertexCount;

	private:

		void createMeshFromMeshBuilder(std::string _name, GLuint _iD, size_t _vertexCount);

		void rename(std::string _path);

	};
}