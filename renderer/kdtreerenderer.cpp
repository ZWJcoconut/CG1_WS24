#include "camera/camera.h"
#include "renderer/kdtreerenderer.h"
#include "scene/fastscene.h"
#include <iostream>

Texture KDTreeRenderer::renderImage(Scene const &scene, Camera const &camera, int width, int height) {
  Texture image(width, height);
  std::cout << "KD Tree renderer will only output KD Tree visualization" << std::endl;
  return image;
}

Texture KDTreeRenderer::renderKDTree(FastScene const &scene, Camera const &camera, int width, int height) {
  Texture image(width, height);

  // IMPLEMENT ME

  return image;
}