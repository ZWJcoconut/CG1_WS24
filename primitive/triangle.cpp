#include "primitive/triangle.h"
#include <algorithm>

// Constructor /////////////////////////////////////////////////////////////////

Triangle::Triangle(std::shared_ptr<Shader> const &shader) : Primitive(shader) {}

Triangle::Triangle(Vector3d const &a, Vector3d const &b, Vector3d const &c, std::shared_ptr<Shader> const &shader) : Primitive(shader), vertex{a, b, c} {}

Triangle::Triangle(Vector3d const &a, Vector3d const &b, Vector3d const &c, Vector3d const &na, Vector3d const &nb, Vector3d const &nc, std::shared_ptr<Shader> const &shader) : Primitive(shader), vertex{a, b, c}, normal{na, nb, nc} {}

Triangle::Triangle(Vector3d const &a, Vector3d const &b, Vector3d const &c, Vector3d const &na, Vector3d const &nb, Vector3d const &nc, Vector2d const &ta, Vector2d const &tb, Vector2d const &tc, std::shared_ptr<Shader> const &shader)
    : Primitive(shader), vertex{a, b, c}, normal{na, nb, nc}, surface{ta, tb, tc} {}

Triangle::Triangle(Vector3d const &a, Vector3d const &b, Vector3d const &c, Vector3d const &na, Vector3d const &nb, Vector3d const &nc, Vector3d const &tana, Vector3d const &tanb, Vector3d const &tanc, Vector3d const &ba,
                   Vector3d const &bb, Vector3d const &bc, Vector2d const &ta, Vector2d const &tb, Vector2d const &tc, std::shared_ptr<Shader> const &shader)
    : Primitive(shader), vertex{a, b, c}, normal{na, nb, nc}, tangent{tana, tanb, tanc}, bitangent{ba, bb, bc}, surface{ta, tb, tc} {}

// Primitive functions /////////////////////////////////////////////////////////


bool Triangle::intersect(Ray &ray) const {
  // IMPLEMENT ME!

  // Determine whether the ray intersects the triangle

  // Test whether this is the foremost primitive in front of the camera

  // (Optional for now) Calculate the normal

  // (Optional for now) Calculate the surface position

  // Set the new length and the current primitive

  return false;
}

// Bounding box ////////////////////////////////////////////////////////////////

float Triangle::minimumBounds(int dimension) const { return std::min(this->vertex[0][dimension], std::min(this->vertex[1][dimension], this->vertex[2][dimension])); }

float Triangle::maximumBounds(int dimension) const { return std::max(this->vertex[0][dimension], std::max(this->vertex[1][dimension], this->vertex[2][dimension])); }
