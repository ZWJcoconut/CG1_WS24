#include "scene/scene.h"
#include "shader/refractionshader.h"

RefractionShader::RefractionShader(float indexInside, float indexOutside) : indexInside(indexInside), indexOutside(indexOutside) {}

Color RefractionShader::shade(Scene const &scene, Ray const &ray) const {
  // IMPLEMENT ME
  // Calculate the refracted ray using the surface normal vector and
  // indexInside, indexOutside
  // Also check for total internal reflection
  // Send out a new refracted ray into the scene; recursively call traceRay()
  return Color(1, 0, 0);
}

bool RefractionShader::isTransparent() const { return true; }
