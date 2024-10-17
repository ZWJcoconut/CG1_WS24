#include "camera/camera.h"
#include "renderer/simplerenderer.h"
#include "scene/scene.h"
#include <iostream>
#include <chrono>
#include <iomanip>

Texture SimpleRenderer::renderImage(Scene const &scene, Camera const &camera, int width, int height) {
  Texture image(width, height);

  // Calculate the aspect ratio

  // Create the image by casting one ray into the scene for each pixel

  return image;
}
