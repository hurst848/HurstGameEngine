#include <memory>

namespace HGE
{
	/*! \brief Is a strucure that stores environmental data
	*
	* The Environment Structure stores data that needs to kept seperate from core.
	* This data includes the Camera as well as the calculation of deltaTime.
	*/
	struct GameEnvironment
	{
		friend struct Camera;
		friend struct MeshRenderer;
		

	public:
		//! Initailizes the Environment and acts as a constructor, returns a shared pointer to a new Environment (shared_ptr<Environment>)
		std::shared_ptr<GameEnvironment> Initialize();

		//! Is called every update of the Core, updates the deltaTime
		void Update();
		//! Returns the deltaTime (float)
		float GetDeltaTime();
	private:
		

		
		std::shared_ptr<Camera> mainCamera;


		float lastTime;
		float deltaTime;

		

	};
}

