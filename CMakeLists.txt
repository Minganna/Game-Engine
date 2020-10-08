cmake_minimum_required(VERSION 2.6)
project(ENGINE)

include_directories(
src
)

if(MSVC)
include_directories(
${PROJECT_SOURCE_DIR}/contrib/msvc-windows-i86/include
)
link_directories(
${PROJECT_SOURCE_DIR}/contrib/msvc-windows-i86/lib
)
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
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

add_library(engine 

src/engine/Core.cpp
src/engine/Entity.cpp

src/engine/Core.h
src/engine/Entity.h
src/engine/Component.h
)
target_link_libraries(engine rend)

add_executable(demo 
src/demo/main.cpp
)

target_link_libraries(demo engine)

