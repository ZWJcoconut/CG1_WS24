#include "light/light.h"
#include "scene/scene.h"
#include "shader/phongshader.h"

PhongShader::PhongShader(Color const &diffuseColor, float diffuseCoefficient, Color const &specularColor,
                         float specularCoefficient, float shininessExponent)
    : diffuseColor(diffuseColor), diffuseCoefficient(diffuseCoefficient), specularColor(specularColor),
      specularCoefficient(specularCoefficient), shininessExponent(shininessExponent) {}

Color PhongShader::shade(Scene const &scene, Ray const &ray) const {
  Color fragmentColor;

  // IMPLEMENT ME

  return fragmentColor;
}
