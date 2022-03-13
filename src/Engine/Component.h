#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>

namespace HGE
{
	struct Core;
	/*! \brief Is the parent Structure to all Components, and user made functionallity
	*
	* The Component Structure is where the majority of the logic in the game engine is derived.
	* Users can make their own components by inheriting from it. Are stored in a vector held within
	* their respective Entity.
	*
	*/
	struct Component
	{
		friend struct Entity;

	public:
		//! Returns a shared pointer to the game engine Core (shared_ptr<Core>)
		std::shared_ptr<Core> GetCore();
		//! Returns a shared pointer to the component's Entity (shared_ptr<Entity>)
		std::shared_ptr<Entity> GetEntity();
		//! Stores a weak pointer to itself (weak_ptr<Component>)
		std::weak_ptr<Component> Self;

	protected:
		//! Vitual function to be implemented by child structures, is called whenever the component is created
		virtual void onCreate() {}
		//! Vitual function to be implemented by child structures, is called whenever the Core is started  
		virtual void onStart() {}
		//! Vitual function to be implemented by child structures, is called every update of the Core and Entity
		virtual void onUpdate() {}
		//! Vitual function to be implemented by child structures, is called every update of the Core and Entity after onUpdate() 
		virtual void onRender() {}
		//! Vitual function to be implemented by child structures, is called every update of the Core and Entity after onRender()
		virtual void onPostRender() {}

	private:
		std::weak_ptr<Entity> entity;
	};
}

#endif // !_COMPONENT_H_


