#ifndef SCENE_H
#define SCENE_H

#include "common/color.h"
#include "common/ray.h"
#include "common/texture.h"
#include "common/vector3d.h"
#include <algorithm>
#include <memory>
#include <vector>

// Forward declarations
class Light;
class Shader;

class Scene {

public:
  // Constructor / Destructor
  Scene() = default;
  virtual ~Scene() = default;

  // Get
  std::vector<std::shared_ptr<Light>> const &lights() const { return this->lights_; }
  std::vector<std::shared_ptr<Primitive>> const &primitives() const { return this->primitives_; }
 
  // Getter method for backgroundColor 
  Color getBackgroundColor() const { return backgroundColor; }
  // Set
  void setBackgroundColor(Color const &color) { this->backgroundColor = color; }
  void setEnvironmentMap(std::shared_ptr<Texture> const &map) { this->environmentMap = map; }

  // Setup functions
  void add(const std::shared_ptr<Light> &light);
  void add(const std::shared_ptr<Primitive> &primitive);

  // Raytracing functions
  Color traceRay(Ray &ray) const;
  virtual bool findIntersection(Ray &ray) const = 0;
  virtual bool findOcclusion(Ray &ray) const = 0;

protected:
  Color backgroundColor;
  std::shared_ptr<Texture> environmentMap;

private:
  std::vector<std::shared_ptr<Light>> lights_;
  std::vector<std::shared_ptr<Primitive>> primitives_;
};

#endif
