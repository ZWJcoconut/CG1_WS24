#include "light/pointlight.h"
#include "scene/scene.h"

PointLight::PointLight(Vector3d const &position, float intensity, Color const &color) : Light(intensity, color), position(position) {}

Light::Illumination PointLight::illuminate(Scene const &scene, Ray const &ray) const {
  // IMPLEMENT ME
  // Get the point on the surface

  // Create an instance of the Illumination object, fill in the direction (from
  // surface point to light source)
  Light::Illumination illum;

  // Define a secondary ray from the surface point to the light source.

  // If the target is not in shadow... (use scene.findOcclusion())

  // Compute the brightness-color of this light using inverse squared distance
  // to light source (i.e. 1/(d^2)), the color of this light source and the
  // intensity

  return illum;
}
