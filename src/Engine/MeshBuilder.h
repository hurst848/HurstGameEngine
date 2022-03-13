#include "Maths.h"

#include <string>
#include <vector>
#include <memory>

namespace HGE
{
	struct Mesh;
	/*! \brief Used to create Mesh Structures
	*
	* The MeshBuilder Structure creates Mesh resources, given programmed / user inputed data 
	*/
	struct MeshBuilder
	{
		friend struct Assets;
	public:
		//! Creates and returns a Mesh (shared_ptr<Mesh>) given: a name (string), a list of verticies (vector<vec3>), a list of texture coordinates (vector<vec2>) 
		std::shared_ptr<Mesh> CreateMesh(std::string _name, std::vector<vec3> _verticies, std::vector<vec2> _textureCoordinates);
		//! Creates and returns a Mesh (shared_ptr<Mesh>) given: a name (string), a list of verticies (vector<vec3>), a list of texture coordinates (vector<vec2>), a list of surface normals (vector<vec3>)
		std::shared_ptr<Mesh> CreateMesh(std::string _name, std::vector<vec3> _verticies, std::vector<vec2> _textureCoordinates, std::vector<vec3> _normals);
		
	private:
		std::shared_ptr<MeshBuilder> Initialize(std::shared_ptr<Assets> _assets);

		std::shared_ptr<Assets> assets;
	};
}