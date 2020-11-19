#include "Component.h"

#include <rend/rend.h>

#include <memory>

namespace myengine
{
struct Texture;
struct Shader;
struct Model;
struct Renderer : public Component
{
  void onInitialize();
  void onRender();

private:
  std::shared_ptr<rend::Shader> shader;
  std::shared_ptr<Model> shape;
  std::shared_ptr<rend::Buffer> coord;
  std::shared_ptr<Texture> texture;
  std::shared_ptr<Shader> shaderfile;

};

}