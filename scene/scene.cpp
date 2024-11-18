#include "light/light.h"
#include "primitive/triangle.h"
#include "scene/scene.h"
#include "shader/shader.h"
#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

const std::string WHITESPACE = " \n\r\t\f\v";
std::string ltrim(const std::string &s) {
  size_t start = s.find_first_not_of(WHITESPACE);
  return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s) {
  size_t end = s.find_last_not_of(WHITESPACE);
  return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s) { return rtrim(ltrim(s)); }

void Scene::add(const std::shared_ptr<Light> &light) { this->lights_.push_back(light); }

void Scene::add(const std::shared_ptr<Primitive> &primitive) {
  assert(primitive->shader() != nullptr);
  this->primitives_.push_back(primitive);
}

void Scene::addObj(char const *fileName, Vector3d const &scale, Vector3d const &translation,
                   const std::shared_ptr<Shader> &shader, bool flipU, bool flipV) {
  std::vector<std::shared_ptr<Primitive>> triangles = loadObj(fileName, scale, translation, shader, flipU, flipV);
  this->primitives_.insert(this->primitives_.end(), std::make_move_iterator(triangles.begin()),
                           std::make_move_iterator(triangles.end()));
}

std::vector<std::shared_ptr<Primitive>> Scene::loadObj(char const *fileName, Vector3d const &scale,
                                                       Vector3d const &translation,
                                                       const std::shared_ptr<Shader> &shader, bool flipU, bool flipV) {
  std::vector<std::shared_ptr<Primitive>> faces;
  std::vector<std::array<int, 3>> indices;

  // IMPLEMENT ME

  return faces;
}

Color Scene::traceRay(Ray &ray) const {
  if (this->findIntersection(ray) && ray.remainingBounces-- > 0) {
    // If the ray has hit an object, call the shader ...
    return ray.primitive->shader()->shade(*this, ray);
  } else if (this->environmentMap) {
    // ... otherwise look up the environment map ...
    float const phi = std::acos(ray.direction.y);
    float const rho = std::atan2(ray.direction.z, ray.direction.x) + float(PI);
    return this->environmentMap->color(rho / (2.0f * float(PI)), phi / float(PI));
  } else {
    // ... if all else fails, just return the background color
    return this->backgroundColor;
  }
}
