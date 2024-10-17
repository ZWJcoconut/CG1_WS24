#include "common/ray.h"
#include "primitive/sphere.h"

// Constructor /////////////////////////////////////////////////////////////////

Sphere::Sphere(std::shared_ptr<Shader> const &shader) : Primitive(shader), radius(0.5f) {}

Sphere::Sphere(Vector3d const &center, float radius, std::shared_ptr<Shader> const &shader)
    : Primitive(shader), center(center), radius(radius) {}

// Primitive functions /////////////////////////////////////////////////////////

bool Sphere::intersect(Ray &ray) const {
  // IMPLEMENT ME!

  // Determine whether the ray intersects the sphere

  // Test whether this is the foremost primitive in front of the camera

  // (Optional for now) Calculate the normal

  // (Optional for now) Calculate the surface position

  // Set the new length and the current primitive

  return false;
}

// Bounding box ////////////////////////////////////////////////////////////////

float Sphere::minimumBounds(int dimension) const { return this->center[dimension] - this->radius; }

float Sphere::maximumBounds(int dimension) const { return this->center[dimension] + this->radius; }
