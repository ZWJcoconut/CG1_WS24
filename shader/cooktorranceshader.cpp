#include "light/light.h"
#include "scene/scene.h"
#include "shader/cooktorranceshader.h"

CookTorranceShader::CookTorranceShader(Color const &diffCol, Color const &ctCol, float IOR, float roughness, float diffCoeff, float ctCoeff) : diffuseColor(diffCol * diffCoeff), ctColor(ctCol * ctCoeff), F0(IOR), m(roughness) {}

Color CookTorranceShader::shade(Scene const &scene, Ray const &ray) const {
  Color fragmentColor;

  // IMPLEMENT ME

  return fragmentColor;
}