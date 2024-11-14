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

  // Calculate min and max bounds based on center and size
  /*
  float xMin = center.x - size.x / 2;
  float xMax = center.x + size.x / 2;

  float yMin = center.y - size.y / 2;
  float yMax = center.y + size.y / 2;

  float zMin = center.z - size.z / 2;
  float zMax = center.z + size.z / 2;

  // Intersection calculation
  float tx_min = (xMin - ray.origin.x) / ray.direction.x;
  float tx_max = (xMax - ray.origin.x) / ray.direction.x;
  if(tx_min > tx_max) std::swap(tx_min,tx_max);

  float ty_min = (yMin - ray.origin.y) / ray.direction.y;
  float ty_max = (yMax - ray.origin.y) / ray.direction.y;
  if(ty_min > ty_max) std::swap(ty_min,ty_max);

  float tz_min = (zMin - ray.origin.z) / ray.direction.z;
  float tz_max = (zMax - ray.origin.z) / ray.direction.z;
  if(tz_min > tz_max) std::swap(tz_min,tz_max);

  // t_enter = max{tmin}, t_exit = min{tmax}
  float t_in = std::max(std::max(tx_min,ty_min),tz_min);
  float t_out = std::min(std::min(tx_max,ty_max),tz_max);
  // Check for valid intersection
  if (t_in > t_out || t_out < 0) {
    // Ray misses the box
    return false;
  } else {
    // determine the surface Normal based on which face of the box was hit
    if(t_in == tx_min)
    {
      // Hit on the X face 
      ray.normal = (ray.direction.x > 0 ) ? Vector3d(1,0,0) : Vector3d(-1,0,0);
    }
    else if(t_in == ty_min)
    {
      ray.normal = (ray.direction.y > 0) ? Vector3d(0,1,0) : Vector3d(0,-1,0);
    }
    else
    {
      ray.normal = (ray.direction.z > 0) ? Vector3d(0,0,1) : Vector3d(0,0,-1);
    }
    // Set intersection data on the ray
    ray.length = t_in;           // Update ray length to the closest intersection distance
    ray.primitive = this;        // Set the intersected primitive to this box
    return true;                 // Intersection detected
  }
  */

// Set the new length and the current primitive
  float tmin = (minimumBounds(0) - ray.origin[0]) / ray.direction[0];
  float tmax = (maximumBounds(0) - ray.origin[0]) / ray.direction[0];
  Vector3d normal(1, 0, 0);
  if (tmin > tmax)
  {
    std::swap(tmin, tmax);
    normal = Vector3d(-1, 0, 0);
  }
  for (int i = 1; i < 3; i++)
  {
    float t1 = (minimumBounds(i) - ray.origin[i]) / ray.direction[i];
    float t2 = (maximumBounds(i) - ray.origin[i]) / ray.direction[i];
    Vector3d currentNormal(0, 0, 0);
    currentNormal[i] = 1;

    if (t1 > t2)
    {
      std::swap(t1, t2);
      currentNormal[i] = -1;
    }

    if ((tmin > t2) || (t1 > tmax))
    {
      return false;
    }
    if (t1 > tmin)
    {
      tmin = t1;
      normal = currentNormal;
    }
    if (t2 < tmax)
      tmax = t2;
  }

  if (tmin > 0)
  {
    ray.length = tmin;
    ray.primitive = this;
    ray.normal = normal;
    return true;
  }

  return false;
}

// Bounding box /////////////////


// Bounding box ////////////////////////////////////////////////////////////////

float Box::minimumBounds(int dimension) const { return this->center[dimension] - this->size[dimension] / 2; }

float Box::maximumBounds(int dimension) const { return this->center[dimension] + this->size[dimension] / 2; }
