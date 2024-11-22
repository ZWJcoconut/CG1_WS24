#include "light/light.h"
#include "scene/scene.h"
#include "shader/lambertshader.h"

LambertShader::LambertShader(Color const &diffuseColor) : diffuseColor(diffuseColor) {}

Color LambertShader::shade(Scene const &scene, Ray const &ray) const {
  Color fragmentColor;

  // IMPLEMENT ME

  return fragmentColor;
}
