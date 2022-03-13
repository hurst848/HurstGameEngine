#include "Mesh.h"

#include "misc/bugl/bugl.h"

namespace HGE
{
	void Mesh::Load(const std::string& _path)
	{
		ID = buLoadModel(_path, &VertexCount);
		rename(_path);
	}

	void Mesh::rename(std::string _path)
	{
		while (_path.find("/") != std::string::npos)
		{
			_path = _path.substr(1);
		}
		std::string rtrn = _path.substr(0, _path.find(".")) + ".msh";
		Name = rtrn;
	}

	void Mesh::createMeshFromMeshBuilder(std::string _name, GLuint _iD, size_t _vertexCount)
	{
		ID = _iD;
		Name = _name;
		VertexCount = _vertexCount;
	}

}