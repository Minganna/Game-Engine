#include "Component.h"

#include <rend/rend.h>

#include <memory>

namespace myengine
{
struct Texture;
struct Shader;
struct Model;
/// <summary>
/// struct used to render object in the scene
/// </summary>
struct Renderer : public Component
{
	/// <summary>
	/// first function called on component added
	/// </summary>
	/// <param name="shaderpath"></param>
	/// <param name="texurepath"></param>
	/// <param name="modelpath"></param>
	void onInitialize(std::string shaderpath, std::string texurepath, std::string modelpath);
	/// <summary>
	/// function called on rendered
	/// </summary>
	void onRender();

private:
  /// <summary>
  /// pointer to the rend::shader struct
  /// </summary>
  std::shared_ptr<rend::Shader> shader;
  /// <summary>
  /// pointer to the model struct
  /// </summary>
  std::shared_ptr<Model> shape;
  /// <summary>
  /// pointer to the texture struct
  /// </summary>
  std::shared_ptr<Texture> texture;
  /// <summary>
  /// pointer to the shader struct
  /// </summary>
  std::shared_ptr<Shader> shaderfile;

};

}