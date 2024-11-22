#include "light/light.h"
#include "scene/scene.h"
#include "shader/brdfshader.h"

BrdfShader::BrdfShader(char const *fileName, Color const &scale)
    : scale(scale), brdf(std::make_unique<BRDFRead>(fileName)) {}

Color BrdfShader::shade(Scene const &scene, Ray const &ray) const {
  Color illuminationColor;

  // IMPLEMENT ME
  return illuminationColor;
}
