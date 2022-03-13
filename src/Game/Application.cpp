#include "Engine/HGE.h"

#include "PlayerController.h"
#include "OponentController.h"
#include "BallController.h"

#include <memory>
#include <string>
#include <vector>

using namespace HGE;



int main()
{
	// Create Core
	std::shared_ptr<Core> core = Core().Initialize();

	// Load Resources

	std::shared_ptr<Shader> vertex = core->Resources->AddResource<Shader>("../shaders/lightShader.vert");
	std::shared_ptr<Shader> fragment = core->Resources->AddResource<Shader>("../shaders/lightShader.frag");

	std::shared_ptr<Mesh> paddleMesh = core->Resources->AddResource<Mesh>("../meshes/paddel.obj");
	std::shared_ptr<Texture> paddleTexture = core->Resources->AddResource<Texture>("../textures/metalPlate.png");

	std::shared_ptr<Mesh> ballMesh = core->Resources->AddResource<Mesh>("../meshes/sphere.obj");
	std::shared_ptr<Texture> ballTexture = core->Resources->AddResource<Texture>("../textures/sphereTexture.png");

	std::shared_ptr<Mesh> logMesh = core->Resources->AddResource<Mesh>("../meshes/log.obj");
	std::shared_ptr<Texture> logTexture = core->Resources->AddResource<Texture>("../textures/log.png");

	std::shared_ptr<Sound> BallHitSound = core->Resources->AddResource<Sound>("../sounds/hit.ogg");
	std::shared_ptr<Sound> OpponentWinSound = core->Resources->AddResource<Sound>("../sounds/OpponentScored.ogg");
	std::shared_ptr<Sound> PlayerWinSound = core->Resources->AddResource<Sound>("../sounds/PlayerScored.ogg");

	// Create Camera
	std::weak_ptr<Entity> cam = core->AddEntity();
		std::weak_ptr<Camera> cameraComponent = cam.lock()->AddComponent<Camera>();
			cameraComponent.lock()->SetAsMainCamera();
		std::weak_ptr<AudioListener> listener = cam.lock()->AddComponent<AudioListener>();
			listener.lock()->SetActiveListner();
		std::weak_ptr<AudioListener> camListener = cam.lock()->AddComponent<AudioListener>();
			camListener.lock()->SetSelf(camListener.lock());
			camListener.lock()->SetActiveListner();
	
	// Create bounding logs
	std::weak_ptr<Entity> topLog = core->AddEntity();
		std::weak_ptr<MeshRenderer> tlRenderer = topLog.lock()->AddComponent<MeshRenderer>();
			std::shared_ptr<ShaderProgram> tlProgram = std::make_shared<ShaderProgram>();
				tlProgram->AddShader(vertex);
				tlProgram->AddShader(fragment);
				tlProgram->Compile();
			tlRenderer.lock()->SetMesh(logMesh);
			tlRenderer.lock()->SetTexture(logTexture);
			tlRenderer.lock()->SetShader(tlProgram);
			tlRenderer.lock()->Render = true;
		topLog.lock()->GetTransform()->SetPosition(-16, 4.75, -8);
		std::weak_ptr<BoxCollider> tlCollider = topLog.lock()->AddComponent<BoxCollider>();
			tlCollider.lock()->SetHalfExtents(vec3(1000.0f, 1, 0.5f));
			tlCollider.lock()->Tag = "TopLog";
			tlCollider.lock()->RegisterCollider(tlCollider.lock());

	std::weak_ptr<Entity> bottomLog = core->AddEntity();
		std::weak_ptr<MeshRenderer> blRenderer = bottomLog.lock()->AddComponent<MeshRenderer>();
			std::shared_ptr<ShaderProgram> blProgram = std::make_shared<ShaderProgram>();
				blProgram->AddShader(vertex);
				blProgram->AddShader(fragment);
				blProgram->Compile();
			blRenderer.lock()->SetMesh(logMesh);
			blRenderer.lock()->SetTexture(logTexture);
			blRenderer.lock()->SetShader(blProgram);
			blRenderer.lock()->Render = true;
		bottomLog.lock()->GetTransform()->SetPosition(-16, -4.75, -8);
		std::weak_ptr<BoxCollider> blCollider = bottomLog.lock()->AddComponent<BoxCollider>();
			blCollider.lock()->SetHalfExtents(vec3(1000.0f, 1, 0.5f));
			blCollider.lock()->Tag = "BottomLog";
			blCollider.lock()->RegisterCollider(blCollider.lock());

	// Create Ball
	std::weak_ptr<Entity> ball = core->AddEntity();
		std::weak_ptr<MeshRenderer> ballRenderer = ball.lock()->AddComponent<MeshRenderer>();
			std::shared_ptr<ShaderProgram> ballProgram = std::make_shared<ShaderProgram>();
				ballProgram->AddShader(vertex);
				ballProgram->AddShader(fragment);
				ballProgram->Compile();
			ballRenderer.lock()->SetMesh(ballMesh);
			ballRenderer.lock()->SetTexture(ballTexture);
			ballRenderer.lock()->SetShader(ballProgram);
			ballRenderer.lock()->Render = true;
		ball.lock()->GetTransform()->SetPosition(0, 0, -8);
		ball.lock()->GetTransform()->SetScale(0.5f, 0.5f, 0.5f);
		std::weak_ptr<SphereCollider> bCollider = ball.lock()->AddComponent<SphereCollider>();
			bCollider.lock()->SetRadius(1.0f);
			bCollider.lock()->Tag = "Ball";
			bCollider.lock()->RegisterCollider(bCollider.lock());
		std::weak_ptr<AudioPlayer> ballPlayer = ball.lock()->AddComponent<AudioPlayer>();
			ballPlayer.lock()->SetSoundClip(BallHitSound);
		std::weak_ptr<BallController> bController = ball.lock()->AddComponent<BallController>();
			bController.lock()->BallSpeed = 4.0f;
			bController.lock()->collider = bCollider;
			bController.lock()->extents = 9.0f;
			bController.lock()->player = ballPlayer.lock();
		

	// Create User Paddle
	std::weak_ptr<Entity> userPaddle = core->AddEntity();
		std::weak_ptr<MeshRenderer> upRenderer = userPaddle.lock()->AddComponent<MeshRenderer>();
			std::shared_ptr<ShaderProgram> upProgram = std::make_shared<ShaderProgram>();
				upProgram->AddShader(vertex);
				upProgram->AddShader(fragment);
				upProgram->Compile();
			upRenderer.lock()->SetMesh(paddleMesh);
			upRenderer.lock()->SetTexture(paddleTexture);
			upRenderer.lock()->SetShader(upProgram);
			upRenderer.lock()->Render = true;
		userPaddle.lock()->GetTransform()->SetPosition(-6.5f, 0, -8);
		std::weak_ptr<AudioPlayer> upPlayer = userPaddle.lock()->AddComponent<AudioPlayer>();
			upPlayer.lock()->SetSoundClip(PlayerWinSound);
		std::weak_ptr<BoxCollider> upCollider = userPaddle.lock()->AddComponent<BoxCollider>();
			upCollider.lock()->SetHalfExtents(vec3(0.5f, 1, 0.5f));
			upCollider.lock()->Tag = "UserPaddle";
			upCollider.lock()->RegisterCollider(upCollider.lock());
		std::weak_ptr<PlayerController> pController = userPaddle.lock()->AddComponent<PlayerController>();
			pController.lock()->PlayerSpeed = 2.5f;
			pController.lock()->extents = 3.3f;
			pController.lock()->player = upPlayer.lock();
		

	// Create Enemy Paddle
	std::weak_ptr<Entity> enemyPaddle = core->AddEntity();
		std::weak_ptr<MeshRenderer> epRenderer = enemyPaddle.lock()->AddComponent<MeshRenderer>();
			std::shared_ptr<ShaderProgram> epProgram = std::make_shared<ShaderProgram>();
				epProgram->AddShader(vertex);
				epProgram->AddShader(fragment);
				epProgram->Compile();
			epRenderer.lock()->SetMesh(paddleMesh);
			epRenderer.lock()->SetTexture(paddleTexture);
			epRenderer.lock()->SetShader(epProgram);
			epRenderer.lock()->Render = true;
		enemyPaddle.lock()->GetTransform()->SetPosition(6.5f, 0, -8);
		std::weak_ptr<AudioPlayer> epPlayer = enemyPaddle.lock()->AddComponent<AudioPlayer>();
			epPlayer.lock()->SetSoundClip(OpponentWinSound);
		std::weak_ptr<BoxCollider> epCollider = enemyPaddle.lock()->AddComponent<BoxCollider>();
			epCollider.lock()->SetHalfExtents(vec3(0.5f, 1, 0.5f));
			epCollider.lock()->Tag = "EnemyPaddle";
			epCollider.lock()->RegisterCollider(epCollider.lock());
		std::weak_ptr<OpponentController>oController = enemyPaddle.lock()->AddComponent<OpponentController>();
			oController.lock()->ball = ball.lock();
			oController.lock()->OpponentSpeed = 2.5f;
			oController.lock()->extents = 3.3f;
			oController.lock()->player = epPlayer.lock();
		
	// Final assignements
	bController.lock()->opp = epPlayer.lock();
	bController.lock()->plyr = upPlayer.lock();
	// Start the Engine
	core->StartEngine();

	return 0;
}


