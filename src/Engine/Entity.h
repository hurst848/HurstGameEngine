#include <memory>
#include <vector>

namespace HGE
{
	struct Component;
	struct Transform;
	/*! \brief Is a strucure that stores all components
	*
	* The Entity Structure acts as a 'GameObject', and is a object within the game space.
	* Functionally, it stores all of the components and data to allow for programibility
	*/
	struct Entity
	{
		friend struct Core;

	public:
		//! Returns a shared pointer to the game engine Core (shared_ptr<Core>)
		std::shared_ptr<Core> GetCore();

		//! Template funtion to add a new component to the Entity and return the added component (shared_ptr<T>), given the component type (T)
		template<typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> _component = std::make_shared<T>();
			_component->Self = _component;
			_component->entity = Self.lock();

			_component->onCreate();
			components.push_back(_component);

			return _component;
		}

		//! Template funtion to add a return a component (shared_ptr<T>), given the component type (T)
		template<typename T>
		std::shared_ptr<T> GetComponent()
		{
			for (size_t i = 0; i < components.size(); i++)
			{
				std::shared_ptr<T> rtrn = std::dynamic_pointer_cast<T>(components.at(i));
				if (rtrn)
				{
					return rtrn;
				}
			}
		}
		//! Weak pointer pointing to Self (weak_ptr<Assets>)
		std::weak_ptr<Entity> Self;
		//! Returns the transform component (shared_ptr<Transform>) attached to this Entity
		std::shared_ptr<Transform> GetTransform();

		//! Marks the entity for deletion 
		void MarkForDeletion() { toBeDeleted = true; }

	private:

		void onCreate();
		void onStart();
		void onUpdate();
		void onRender();
		void onPostRender();

		bool toBeDeleted = false;

		std::vector< std::shared_ptr<Component> > components;

		std::weak_ptr<Core> core;

		std::weak_ptr<Transform> transform;
	};
}