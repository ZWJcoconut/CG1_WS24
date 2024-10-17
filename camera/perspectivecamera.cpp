#include "camera/perspectivecamera.h"

PerspectiveCamera::PerspectiveCamera() : forwardDirection(0, 0, 1), upDirection(0, 1, 0), rightDirection(1, 0, 0) { setFovAngle(70); }

Ray PerspectiveCamera::createRay(float x, float y) const {
  // IMPLEMENT ME!
  // Use the orthonormal basis of the image plane to define a ray through the specified point
  return Ray();
}
