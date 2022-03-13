#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <string>

namespace HGE
{
	/*! \brief Is a parent structure to all Resources
	*
	* The Resource Structure acts as a template for all resouces to follow
	*/
	struct Resource
	{
	public:
		//! Stores the name of the resource (string)
		std::string Name;

	private:
		virtual void Load(const std::string& _path) {}
	};
}

/*
*	Naming Convention for Resources
* 
*	*.snd	= Sound File
*	*.msh	= Mesh
*	*.txtr	= Texture
*	*.ent	= Entity
* 
*/

#endif // !_RESOURCE_H_
