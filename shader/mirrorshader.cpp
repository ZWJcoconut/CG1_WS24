#include "scene/scene.h"
#include "shader/mirrorshader.h"

MirrorShader::MirrorShader() {}

Color MirrorShader::shade(Scene const &scene, Ray const &ray) const {
  // IMPLEMENT ME
  // Calculate the reflection vector
  // Create a new reflection ray
  // Send the new ray out into the scene and return the result
  return Color(0, 0, 1);
}
