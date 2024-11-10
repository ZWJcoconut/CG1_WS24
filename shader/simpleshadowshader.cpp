#include "light/light.h"
#include "scene/scene.h"
#include "shader/simpleshadowshader.h"

SimpleShadowShader::SimpleShadowShader(Color const &objectColor) : objectColor(objectColor) {}

Color SimpleShadowShader::shade(Scene const &scene, Ray const &ray) const {
  // IMPLEMENT ME
  // loop over all light sources to check for visibility and multiply "light
  // strength" with this objects albedo (color)
  return Color(0, 1, 0);
}
