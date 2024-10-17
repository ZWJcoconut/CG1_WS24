#ifndef SIMPLERENDERER_H
#define SIMPLERENDERER_H

#include "renderer/renderer.h"

class SimpleRenderer : public Renderer {

public:
  // Constructor / Destructor
  SimpleRenderer() = default;
  ~SimpleRenderer() override = default;

  // Render functions
  Texture renderImage(Scene const &scene, Camera const &camera, int width, int height) override;
};

#endif
