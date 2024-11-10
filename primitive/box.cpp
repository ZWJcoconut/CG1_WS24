#include "common/ray.h"
#include "primitive/box.h"
#include <cmath>
#include <utility>

// Constructor /////////////////////////////////////////////////////////////////

Box::Box(std::shared_ptr<Shader> const &shader) : Primitive(shader), size(Vector3d(1, 1, 1)) {}

Box::Box(Vector3d const &center, Vector3d const &size, std::shared_ptr<Shader> const &shader)
    : Primitive(shader), center(center), size(size) {}

// Primitive functions /////////////////////////////////////////////////////////

bool Box::intersect(Ray &ray) const {
  // IMPLEMENT ME!

  // Determine whether the ray intersects the box

  // Test whether this is the foremost primitive in front of the camera

  // (Optional for now) Calculate the normal

  // (Optional for now) Calculate the surface position

  // Set the new length and the current primitive

  return false;
}

// Bounding box ////////////////////////////////////////////////////////////////

float Box::minimumBounds(int dimension) const { return this->center[dimension] - this->size[dimension] / 2; }

float Box::maximumBounds(int dimension) const { return this->center[dimension] + this->size[dimension] / 2; }
