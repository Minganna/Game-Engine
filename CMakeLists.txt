cmake_minimum_required(VERSION 2.6)
project(ENGINE)

string(TOLOWER "${CMAKE_CXX_COMPILER_ID}" COMP)
string(TOLOWER "${CMAKE_SYSTEM_NAME}" PLATFORM)
string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" ARCH)
message("${COMP}-${PLATFORM}-${ARCH}")

add_definitions(-DSDL_MAIN_HANDLED)

if(NOT MSVC AND NOT MINGW)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --preload-file resources -s USE_SDL=2 -s DISABLE_EXCEPTION_CATCHING=0")
	set(CMAKE_EXECUTABLE_SUFFIX ".html")
	

endif()
	
include_directories(
  	src
  	${PROJECT_SOURCE_DIR}/contrib/${COMP}-${PLATFORM}-${ARCH}/include
)

link_directories(
  	${PROJECT_SOURCE_DIR}/contrib/${COMP}-${PLATFORM}-${ARCH}/lib
)

if(MINGW)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s -static")
  add_definitions(-DGLEW_STATIC)
  set(STATIC_LIBS imm32 iconv winmm ole32 gdi32 oleaut32 version)
  set(LIBGLEW glew32)
  set(LIBSDL2 SDL2)
elseif(MSVC)
  add_definitions(-DGLEW_STATIC)
  set(STATIC_LIBS imm32 winmm setupapi version)
  set(LIBGLEW glew32s)
  set(LIBSDL2 SDL2-static)
endif()




add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)

if(MSVC OR MINGW)
  target_link_libraries(rend ${LIBGLEW} opengl32 )
else()
  target_link_libraries(rend GLEW GL)
endif()

add_library(engine
  src/engine/Core.cpp
  src/engine/Entity.cpp
  src/engine/Component.cpp
  src/engine/Exception.cpp
  src/engine/Renderer.cpp
  src/engine/Transform.cpp
  src/engine/ResourceManager.cpp
  src/engine/Resource.cpp
  src/engine/Texture.cpp
  src/engine/MeshRenderer.cpp
  src/engine/Keyboard.cpp
  src/engine/Shader.cpp
  src/engine/Model.cpp
  src/engine/Camera.cpp
  src/engine/Sound.cpp
  src/engine/SoundSource.cpp
  src/engine/BoxCollider.cpp
  src/engine/CollisionManager.cpp	

  src/engine/Core.h
  src/engine/Entity.h
  src/engine/Component.h
  src/engine/Exception.h
  src/engine/Renderer.h
  src/engine/Transform.h
  src/engine/ResourceManager.h
  src/engine/Resource.h
  src/engine/Texture.h
  src/engine/stb_image.h
  src/engine/stb_vorbis.h
  src/engine/MeshRenderer.h
  src/engine/Keyboard.h
  src/engine/Shader.h
  src/engine/Model.h
  src/engine/Camera.h
  src/engine/Sound.h
  src/engine/SoundSource.h
  src/engine/BoxCollider.h
  src/engine/CollisionManager.h
)
if(MSVC OR MINGW)
target_link_libraries(engine rend ${LIBSDL2} ${STATIC_LIBS} OpenAL32)
else()
target_link_libraries(engine rend ${LIBSDL2} ${STATIC_LIBS} AL)
endif()


add_executable(demo
  src/demo/main.cpp
  src/demo/Player.cpp
  src/demo/Player.h
)
target_link_libraries(demo engine)