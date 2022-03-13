#include "MeshBuilder.h"

#include "Assets.h"
#include "Mesh.h"

#include "glew.h"

namespace HGE
{
	std::shared_ptr<MeshBuilder> MeshBuilder::Initialize(std::shared_ptr<Assets> _assets)
	{
		std::shared_ptr<MeshBuilder> rtrn = std::make_shared<MeshBuilder>();
		rtrn->assets = _assets;
		return rtrn;
	}


	std::shared_ptr<Mesh> MeshBuilder::CreateMesh(std::string _name, std::vector<vec3> _verticies, std::vector<vec2> _textureCoordinates)
	{
		std::shared_ptr<Mesh> generatedMesh = std::make_shared<Mesh>();

		std::vector<GLfloat> dataBuffer_vertex;
		for (int i = 0; i < _verticies.size(); i++)
		{
			dataBuffer_vertex.push_back(_verticies.at(i).x);
			dataBuffer_vertex.push_back(_verticies.at(i).y);
			dataBuffer_vertex.push_back(_verticies.at(i).z);
		}
		

		std::vector<GLfloat> dataBuffer_texture;
		for (int i = 0; i < _verticies.size(); i++)
		{
			dataBuffer_texture.push_back(_textureCoordinates.at(i).x);
			dataBuffer_texture.push_back(_textureCoordinates.at(i).y);
		}

		std::vector<GLfloat> dataBuffer_normal;
		for (int i = 0; i < _verticies.size() / 3; i++)
		{
			vec3 tmpA = _verticies.at((i * 3) + 1) - _verticies.at((i * 3) + 0);
			vec3 tmpB = _verticies.at((i * 3) + 2) - _verticies.at((i * 3) + 0);
			vec3 fnv = cross(tmpB, tmpA);
			fnv = normalize(fnv);

			dataBuffer_normal.push_back(fnv.x);
			dataBuffer_normal.push_back(fnv.y);
			dataBuffer_normal.push_back(fnv.z);
		}

		GLuint verticesBuffer; 
		glGenBuffers(1, &verticesBuffer);
		if (!verticesBuffer) { throw std::exception(); }
		glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
		glBufferData(GL_ARRAY_BUFFER, dataBuffer_vertex.size() * sizeof(dataBuffer_vertex.at(0)), &dataBuffer_vertex.at(0), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		GLuint textCoordBuffer;
		glGenBuffers(1, &textCoordBuffer);
		if (!textCoordBuffer) { throw std::exception(); }
		glBindBuffer(GL_ARRAY_BUFFER, textCoordBuffer);
		glBufferData(GL_ARRAY_BUFFER, dataBuffer_texture.size() * sizeof(dataBuffer_texture.at(0)), &dataBuffer_texture.at(0), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		GLuint normalCoordBuffer;
		glGenBuffers(1, &normalCoordBuffer);
		if (!normalCoordBuffer) { throw std::exception(); }
		glBindBuffer(GL_ARRAY_BUFFER, normalCoordBuffer);
		glBufferData(GL_ARRAY_BUFFER, dataBuffer_normal.size() * sizeof(dataBuffer_normal.at(0)), &dataBuffer_normal.at(0), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glGenVertexArrays(1, &generatedMesh->ID);
		if (!generatedMesh->ID) { throw std::exception(); }
		glBindVertexArray(generatedMesh->ID);

		glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
		glVertexAttribPointer(0, 3,
			GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindBuffer(GL_ARRAY_BUFFER, textCoordBuffer);
		glVertexAttribPointer(1, 2,
			GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindBuffer(GL_ARRAY_BUFFER, normalCoordBuffer);
		glVertexAttribPointer(2, 3,
			GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);

		generatedMesh->VertexCount = _verticies.size();
		
		assets->AddResource<Mesh>(generatedMesh);

		return generatedMesh;
	}
	std::shared_ptr<Mesh> MeshBuilder::CreateMesh(std::string _name, std::vector<vec3> _verticies, std::vector<vec2> _textureCoordinates, std::vector<vec3> _normals)
	{
		std::shared_ptr<Mesh> generatedMesh = std::make_shared<Mesh>();

		std::vector<GLfloat> dataBuffer_vertex;
		for (int i = 0; i < _verticies.size(); i++)
		{
			dataBuffer_vertex.push_back(_verticies.at(i).x);
			dataBuffer_vertex.push_back(_verticies.at(i).y);
			dataBuffer_vertex.push_back(_verticies.at(i).z);
		}


		std::vector<GLfloat> dataBuffer_texture;
		for (int i = 0; i < _verticies.size(); i++)
		{
			dataBuffer_texture.push_back(_textureCoordinates.at(i).x);
			dataBuffer_texture.push_back(_textureCoordinates.at(i).y);
		}

		std::vector<GLfloat> dataBuffer_normal;
		for (int i = 0; i < _verticies.size() / 3; i++)
		{
			dataBuffer_normal.push_back(_normals.at(i).x);
			dataBuffer_normal.push_back(_normals.at(i).y);
			dataBuffer_normal.push_back(_normals.at(i).z);
		}

		GLuint verticesBuffer;
		glGenBuffers(1, &verticesBuffer);
		if (!verticesBuffer) { throw std::exception(); }
		glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
		glBufferData(GL_ARRAY_BUFFER, dataBuffer_vertex.size() * sizeof(dataBuffer_vertex.at(0)), &dataBuffer_vertex.at(0), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		GLuint textCoordBuffer;
		glGenBuffers(1, &textCoordBuffer);
		if (!textCoordBuffer) { throw std::exception(); }
		glBindBuffer(GL_ARRAY_BUFFER, textCoordBuffer);
		glBufferData(GL_ARRAY_BUFFER, dataBuffer_texture.size() * sizeof(dataBuffer_texture.at(0)), &dataBuffer_texture.at(0), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		GLuint normalCoordBuffer;
		glGenBuffers(1, &normalCoordBuffer);
		if (!normalCoordBuffer) { throw std::exception(); }
		glBindBuffer(GL_ARRAY_BUFFER, normalCoordBuffer);
		glBufferData(GL_ARRAY_BUFFER, dataBuffer_normal.size() * sizeof(dataBuffer_normal.at(0)), &dataBuffer_normal.at(0), GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glGenVertexArrays(1, &generatedMesh->ID);
		if (!generatedMesh->ID) { throw std::exception(); }
		glBindVertexArray(generatedMesh->ID);

		glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
		glVertexAttribPointer(0, 3,
			GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindBuffer(GL_ARRAY_BUFFER, textCoordBuffer);
		glVertexAttribPointer(1, 2,
			GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindBuffer(GL_ARRAY_BUFFER, normalCoordBuffer);
		glVertexAttribPointer(2, 3,
			GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);

		generatedMesh->VertexCount = _verticies.size();

		assets->AddResource<Mesh>(generatedMesh);

		return generatedMesh;
	}

}