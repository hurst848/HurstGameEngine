
#include <memory>
#include <vector>

namespace HGE
{
	struct BoxCollider;
	struct SphereCollider;
	/*! \brief Proccess all collisions and physics updates
	*
	* The PhysicsEngine Structure is a crude implemtation of physics. It stores all of the colliders
	* and checks every update for collisions.
	*/
	struct PhysicsEngine
	{
		friend struct Collider;
		friend struct BoxCollider;
		friend struct SphereCollider;

	public:
		//! Initailizes the PhysicsEngine and acts as a constructor, returns a shared pointer to a new PhysicsEngine (shared_ptr<PhysicsEngine>)
		std::shared_ptr<PhysicsEngine> Initialize();
		//! Is called every update of the Core, checks for collisions
		void Update();

	private:
		std::vector<std::weak_ptr<BoxCollider> > boxcolliders;
		std::vector<std::weak_ptr<SphereCollider> > sphereColliders;

	};

}

