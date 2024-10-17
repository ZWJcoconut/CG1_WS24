#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include "camera/camera.h"

class PerspectiveCamera : public Camera {

public:
  // Constructor / Destructor
  PerspectiveCamera();
  ~PerspectiveCamera() override = default;

  // Set
  void setPosition(Vector3d const &position) { this->position = position; }
  void setForwardDirection(Vector3d const &forwardDirection) {
    // IMPLEMENT ME
    // Set up a left-handed coordinate system,
    // in which the camera looks along the positive z-Axis
  }
  void setUpDirection(Vector3d const &upDirection) {
    // IMPLEMENT ME
    // Set up a left-handed coordinate system,
    // in which the camera looks along the positive z-Axis
  }
  void setFovAngle(float fovAngle) {
    // Calculate the focus, i.e. the distance of an image plane of horizontal extent [-1, 1] and horizontal field
    // of view angle fovAngle
  }

  // Camera functions
  Ray createRay(float x, float y) const override;

protected:
  Vector3d position;
  Vector3d forwardDirection;
  Vector3d upDirection;
  Vector3d rightDirection;
  float focus;
};

#endif
