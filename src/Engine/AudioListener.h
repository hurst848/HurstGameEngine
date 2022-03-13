#include "Component.h"

#include <memory>
#include <iostream>

namespace HGE
{
	struct Transform;

	/*! \brief Is a a positional audio listener
	*
	* The AudioListener, is a componet used to give entities
	* 'ears', and allows for the hearing of postional audio.
	*
	*/
	struct AudioListener : Component
	{
		friend struct Entity;
		friend struct AudioPlayer;
	public:
		//! Sets this AudioListener to be the active one for directional audio
		void SetActiveListner();

		//! Creates a reference to the AudioListener within itself, given a shared_ptr to an AudioListener (shared_ptr<AudioListener>)
		void SetSelf(std::shared_ptr<AudioListener> _self);
	private:
		std::weak_ptr<AudioListener> as;
		std::weak_ptr<Transform> transform;

	protected:
		// Called when created, binds the refences of transform
		void onCreate();
	
	};
}

