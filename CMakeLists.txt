cmake_minimum_required(VERSION 3.0)
project(HURST_ENGINE)

include_directories(
	src
	contrib
)


if (MSVC)
	include_directories(
		contrib/msvc_windows_x86/SDL/include
		contrib/msvc_windows_x86/Glew/include
		contrib/msvc_windows_x86/openALSoft/include
	)
	link_directories(
		${CMAKE_SOURCE_DIR}/contrib/msvc_windows_x86/SDL/lib
		${CMAKE_SOURCE_DIR}/contrib/msvc_windows_x86/Glew/lib
		${CMAKE_SOURCE_DIR}/contrib/msvc_windows_x86/OpenALSoft/lib
	)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
else()
endif()

if (MSVC)
	add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(engine
	src/Engine/Core.h
	src/Engine/Core.cpp
	src/Engine/Entity.h
	src/Engine/Entity.cpp
	src/Engine/Component.h
	src/Engine/Component.cpp
	src/Engine/Resource.h
	src/Engine/Sound.h
	src/Engine/Sound.cpp
	src/Engine/Environment.h
	src/Engine/Environment.cpp
	src/Engine/Screen.h
	src/Engine/Screen.cpp
	src/Engine/Transform.h
	src/Engine/Transform.cpp
	src/Engine/Maths.h
	src/Engine/MeshRenderer.h
	src/Engine/MeshRenderer.cpp
	src/Engine/Mesh.h
	src/Engine/Mesh.cpp
	src/Engine/Shader.h
	src/Engine/Shader.cpp
	src/Engine/Texture.h
	src/Engine/Texture.cpp
	src/Engine/Assets.h
	src/Engine/Assets.cpp
	src/Engine/Input.h
	src/Engine/Input.cpp
	src/Engine/Camera.h
	src/Engine/Camera.cpp
	src/Engine/MeshBuilder.h
	src/Engine/MeshBuilder.cpp

	src/Engine/AudioPlayer.h
	src/Engine/AudioPlayer.cpp
	src/Engine/AudioListener.h
	src/Engine/AudioListener.cpp
	src/Engine/AudioManager.h
	src/Engine/AudioManager.cpp

	src/Engine/PhysicsEngine.h
	src/Engine/PhysicsEngine.cpp
	src/Engine/Collider.h
	src/Engine/Collider.cpp
	src/Engine/BoxCollider.h
	src/Engine/BoxCollider.cpp
	src/Engine/SphereCollider.h
	src/Engine/SphereCollider.cpp
	src/Engine/Rigidbody.h
	src/Engine/Rigidbody.cpp

	src/Engine/HGE.h
)

add_executable(testGame
    src/Game/Application.cpp
	src/Game/PlayerController.h
	src/Game/PlayerController.cpp
	src/Game/OponentController.h
	src/Game/OponentController.cpp
	src/Game/BallController.h
	src/Game/BallController.cpp
)

target_link_libraries(testGame engine)
target_link_libraries(engine 
	SDL2 
	glew32 
	opengl32 
	OpenAL32 
)
