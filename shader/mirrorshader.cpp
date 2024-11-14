// #include "scene/scene.h"
// #include "shader/mirrorshader.h"

// MirrorShader::MirrorShader() {}

// Color MirrorShader::shade(Scene const &scene, Ray const &ray) const {
//   // IMPLEMENT ME
//   // Calculate the reflection vector
//   // Create a new reflection ray
//   // Send the new ray out into the scene and return the result

//   // copy the original ray to modify it
//   Ray reflecRay = ray;
//   // calculate the hit point on intersection
//   Vector3d hitpoint = reflecRay.origin + reflecRay.length * reflecRay.direction;
  
//   // !!! I have problem with getting Normal at the hit point.
//   // 1.idee 
//   Vector3d hitNormal = reflecRay.normal;

//   // compute reflection direction:reflection = direction - 2 * (direction dot normal) * normal 
//   Vector3d reflectionDirec = reflecRay.direction - 2 * (dotProduct(reflecRay.direction, hitNormal)) * hitNormal;
//   reflectionDirec = normalized(reflectionDirec);

//   Ray reflecRay_N = Ray(hitpoint,reflectionDirec);
//   //reflecRay_N = ray.normal;
  
//   reflecRay.origin = hitpoint - reflecRay_N.normal * REFR_EPS;
//   // Trace the reflection ray and get the color
//   Color reflecColor = scene.traceRay(reflecRay_N);

//   return reflecColor;
//   //return Color(0, 0, 1);

// }


#include "scene/scene.h"
#include "shader/mirrorshader.h"
#include "common/vector3d.h"

MirrorShader::MirrorShader() {}

Color MirrorShader::shade(Scene const &scene, Ray const &ray) const {
    // Calculate the reflection vector based on the incoming ray direction and the surface normal
    Vector3d normal = ray.normal;
    Vector3d incidentRay = ray.direction;

    // Reflection direction formula:
    // r_reflect = d - 2 * (d ⋅ n) * n
    Vector3d reflectionDirection = incidentRay - 2 * dotProduct(incidentRay, normal) * normal;
    reflectionDirection = normalized(reflectionDirection); // Normalize the reflection direction

    // Create a small offset to prevent self-intersection
    Vector3d reflectionOrigin = ray.origin + ray.length * ray.direction + reflectionDirection * 1e-4f;

    // Create the reflection ray
    Ray reflectionRay(reflectionOrigin, reflectionDirection);

    // Set remaining bounces for recursive tracing
    reflectionRay.setRemainingBounces(ray.getRemainingBounces() - 1);

    // Recursively trace the reflection ray and return the reflected color
    Color reflectionColor = scene.traceRay(reflectionRay);

    return reflectionColor;
}

/*
 * Reflection formula derivation:
 * Given Snell's law:
 * r_reflect = d - 2 * (d ⋅ n) * n
 * where:
 *   - d: direction of the incoming ray
 *   - n: surface normal at the hit point
 * The reflection vector is calculated by subtracting twice the projection of d onto n.
 */
