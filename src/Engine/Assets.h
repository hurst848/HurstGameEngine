#include "Resource.h"


#include <memory>
#include <vector>
#include <iostream>
#include <string>

namespace HGE 
{
	struct MeshBuilder;

	/*! \brief Holds all the resources used in the project.
	*
	* The assets class holds all the resources used within the game engine.
	* These include Meshes, sounds and textures. The corresponding 
	* naming scheme can be found bellow, for naming and retriving the resources: \n
	* *.snd	= Sound File\n
	* *.msh	= Mesh\n
	* *.txtr = Texture\n
	*/
	struct Assets
	{
	public:
		//! Initializes the Assets Structure
		std::shared_ptr<Assets> Initialize();

		//! Templace Function to retrive a resource, given a type (T) and an assigned name (string)
		template<typename T>
		std::shared_ptr<T> GetResource(std::string _name)
		{
			for (int i = 0; i < resources.size(); i++)
			{
				if (resources.at(i)->Name == _name)
				{
					return resources.at(i);
				}
			}
			return NULL;
		}

		//! Template Funtion to retrive a resource, given the resource type (T)
		template<typename T>
		std::shared_ptr<T> GetResource()
		{
			for (int i = 0; i < resources.size(); i++)
			{
				std::shared_ptr<T> rtrn = std::dynamic_pointer_cast<T>(resources.at(i));
				if (rtrn)
				{
					return rtrn;
				}
			}
		}

		//! Template Function to add a new empty resource, given the resource type (T)
		template<typename T>
		std::shared_ptr<T> AddResource()
		{
			std::shared_ptr<T> resource = std::make_shared<T>();

			resources.push_back(resource);

			return resource;
		}
		
		//! Template Function to add a new empty resource, given the resource type (T) and a shared pointer to a pre-existing resource (shared_ptr<T>) 
		template<typename T>
		std::shared_ptr<T> AddResource(std::shared_ptr<T> _resource)
		{
			std::shared_ptr<T> resource = _resource;

			resources.push_back(resource);

			return resource;
		}

		//! Template Function to add a new empty resource, given the resource type (T) and the file path to required file to create that resource (String)
		template<typename T>
		std::shared_ptr<T> AddResource(std::string _path)
		{
			std::shared_ptr<T> resource = std::make_shared<T>();
			resource->Load(_path);

			resources.push_back(resource);

			return resource;
		}
		//! Weak pointer pointing to Self (weak_ptr<Assets>)
		std::weak_ptr<Assets> Self;
		//! Is a Mesh builder, used to create meshes given verticies and texture coordinates
		std::shared_ptr<MeshBuilder> Meshbuilder;
	private:
		std::vector<std::shared_ptr<Resource>> resources;
	};

}