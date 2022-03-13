#include <vector>
#include <memory>

namespace HGE
{
	struct Entity;
	struct Screen;
	struct Assets;
	struct Inputs;
	struct GameEnvironment;
	struct PhysicsEngine;
	struct AudioManager;

	/*! \brief Is where the game engine actually runs
	*
	* The Core Structure acts as the root node for the entire game engine. 
	* All crucial structure required for operation are stored here. 
	* The game loop also occurs within this structure.
	*
	*/
	struct Core
	{
	public:
		//! Initailizes the game engine and acts as a constructor, returns a shared pointer to a new core (shared_ptr<Core>)
		static std::shared_ptr<Core> Initialize();
		//! Adds a new empty Entity, and returns a shared pointer to the created Entity (shared_ptr<Entity>)
		std::shared_ptr<Entity> AddEntity();
		//! Adds a new Entity, given an existing entity (shared_ptr<Entity>), returns a shared pointer to an entity (shared_ptr<Entity>)
		std::shared_ptr<Entity> AddEntity(std::shared_ptr<Entity> _ent);
		//! Starts the game loop and begins calling the onUpdate, onRender and onPostRender methods
		void StartEngine();
		//! Stops the engine from running and exits the application
		void StopEngine();

		//! Stores a weak pointer to itself (weak_ptr<Core>)
		std::weak_ptr<Core> Self;
		//! Stores a shared pointer to an instance of the Assets structure (shared_ptr<Assets>)
		std::shared_ptr<Assets> Resources;
		//! Stores a shared pointer to an instance of the Inputs structure (shared_ptr<Inputs>)
		std::shared_ptr<Inputs> Input;
		//! Stores a shared pointer to an instance of the GameEnvironment structure (shared_ptr<GameEnvironment>)
		std::shared_ptr<GameEnvironment> Environment;
		//! Stores a shared pointer to an instance of the PhysicsEngine structure (shared_ptr<PhysicsEngine>)
		std::shared_ptr<PhysicsEngine> Physics;
		//! Stores a shared pointer to an instance of the AudioManager structure (shared_ptr<AudioManager>)
		std::shared_ptr<AudioManager> Audio;
	private:

		bool running = true;

		std::vector< std::shared_ptr<Entity> > entities;
		
		

		std::shared_ptr<Screen> screen;

		

	};
}

