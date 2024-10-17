#include "primitive/infiniteplane.h"
#include <cmath>

// Constructor /////////////////////////////////////////////////////////////////

InfinitePlane::InfinitePlane(std::shared_ptr<Shader> const &shader) : Primitive(shader), normal(0, 1, 0) {}

InfinitePlane::InfinitePlane(Vector3d const &origin, Vector3d const &normal, std::shared_ptr<Shader> const &shader)
    : Primitive(shader), origin(origin), normal(normal) {}

// Primitive functions /////////////////////////////////////////////////////////

bool InfinitePlane::intersect(Ray &ray) const {
  // IMPLEMENT ME!

  // Make sure the ray is not coming from the other side (backface culling).
  // Note: We only use backface culling for InfinitePlanes, because we have
  // some special features planned that rely on backfaces for other primitives.

  // Determine whether the ray intersects the plane

  // Test whether this is the foremost primitive in front of the camera

  // (Optional for now) Set the normal

  // Set the new length and the current primitive

  return false;
}

// Bounding box ////////////////////////////////////////////////////////////////

float InfinitePlane::minimumBounds(int dimension) const {
  if (this->normal[dimension] == 1.0f) // plane is orthogonal to the axis
    return this->origin[dimension] - EPSILON;
  else
    return -INFINITY;
}

float InfinitePlane::maximumBounds(int dimension) const {
  if (this->normal[dimension] == 1.0f) // plane is orthogonal to the axis
    return this->origin[dimension] + EPSILON;
  else
    return +INFINITY;
}
