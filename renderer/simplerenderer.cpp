#include "camera/camera.h"
#include "renderer/simplerenderer.h"
#include "scene/scene.h"
#include <iostream>
#include <chrono>
#include <iomanip>

Texture SimpleRenderer::renderImage(Scene const &scene, Camera const &camera, int width, int height) {
  Texture image(width, height);

  // Setup timer
  std::chrono::steady_clock::time_point start, stop;

  // Reset Ray counting
  Ray::resetRayCount();

  // Super-hacky progress bar!
  std::cout << "(SimpleRenderer): Begin rendering..." << std::endl;
  std::cout << "| 0%";
  int const barSize = 50;
  int const stepSize = (width * height) / barSize;
  for (int i = 0; i < barSize - 3 - 5; ++i)
    std::cout << " ";
  std::cout << "100% |" << std::endl << "|";
  int k = 0;

  // Start timer
  start = std::chrono::steady_clock::now();

  float const aspectRatio = static_cast<float>(height) / width;
  for (int x = 0; x < image.width(); ++x) {
    for (int y = 0; y < image.height(); ++y) {
      Ray ray = camera.createRay((static_cast<float>(x) / width * 2 - 1), -(static_cast<float>(y) / height * 2 - 1) * aspectRatio);
      image.setPixelAt(x, y, clamped(scene.traceRay(ray)));

      // Super hacky progress bar!
      if (++k % stepSize == 0) {
        std::cout << "=" << std::flush;
      }
    }
  }

  // Stop timer
  stop = std::chrono::steady_clock::now();

  std::cout << "| Done!" << std::endl;

  // Calculate the Time taken in seconds
  double seconds = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count();

  std::cout << "Time: " << seconds << "s" << std::endl;

  // Get the number of seconds per ray
  int rays = Ray::getRayCount();

  std::cout << "Paths: " << rays << std::endl;
  std::cout << "Paths per second: " << std::fixed << std::setprecision(0) << rays / seconds << std::endl;


  return image;
}
