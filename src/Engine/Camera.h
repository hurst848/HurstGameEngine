#include "Component.h"
#include "Maths.h"

#include <memory>

namespace HGE
{
	/*! \brief Is a Camera for viewing the world
	*
	* The Camera Structure, is a component used to act as camera. It stores the 
	* view matrix for rendering purposes.
	*
	*/
	struct Camera : Component, std::enable_shared_from_this<Camera>
	{
	public:
		//! Returns a mat4 containing the view matrix for this camera
		mat4 GetViewMatrix();
		//! Sets the current camera (this) as the main camera in the GameEnvironment structure, to be used for rendering
		void SetAsMainCamera();
	private:
		
	};
}