/*
#include "light/pointlight.h"
#include "scene/scene.h"

PointLight::PointLight(Vector3d const &position, float intensity, Color const &color) : Light(intensity, color), position(position) {}

Light::Illumination PointLight::illuminate(Scene const &scene, Ray const &ray) const {
  // IMPLEMENT ME
  // Get the point on the surface

  // Create an instance of the Illumination object, fill in the direction (from
  // surface point to light source)
  Light::Illumination illum;

  // Define a secondary ray from the surface point to the light source.

  // If the target is not in shadow... (use scene.findOcclusion())

  // Compute the brightness-color of this light using inverse squared distance
  // to light source (i.e. 1/(d^2)), the color of this light source and the
  // intensity

  return illum;
}
*/
#include "light/pointlight.h"
#include "scene/scene.h"
#include "common/ray.h"
#include <cmath>

PointLight::PointLight(Vector3d const &position, float intensity, Color const &color) : Light(intensity, color), position(position) {}

Light::Illumination PointLight::illuminate(Scene const &scene, Ray const &ray) const {
  // IMPLEMENT ME
  
  // Get the point on the surface  获取交点，即光线射中的表面点
  Vector3d surfacePoint = ray.origin + ray.direction * ray.length;
  // Create an instance of the Illumination object, fill in the direction (from
  // surface point to light source) 初始化光照信息，设置从表面点到光源的方向
  Light::Illumination illum;
  illum.direction = normalized(position - surfacePoint);
  // Define a secondary ray from the surface point to the light source.
  Vector3d offsetPoint = surfacePoint + illum.direction * 1e-4f;  // 防止自相交的小偏移  Define a small offset to prevent self-intersection
    Ray shadowRay(offsetPoint, illum.direction);    // Create a shadow ray from the offset point towards the light source
    shadowRay.length = length(position - surfacePoint);  // 设置阴影射线的长度为到光源的距离   Calculate the distance from the surface point to the light source  这就是公式中的 d_p
  // If the target is not in shadow... (use scene.findOcclusion())
  if (!scene.findOcclusion(shadowRay)) {
        // 如果没有物体阻挡，则计算光强度   If there's no occlusion, compute the attenuation based on the inverse square law
        float distanceSquared = shadowRay.length * shadowRay.length;
        float attenuation = intensity / distanceSquared;  // 距离平方反比衰减  Inverse square distance decay  attenuation = i / d_p^2

        // 计算光源颜色的贡献  Calculate the resulting color contribution from the light source
        illum.color = color * attenuation;    //c_p = (i / d_p^2) * c
    } else {
        // 如果在阴影中，则光照颜色贡献为黑色  If the point is in shadow, the light contribution is zero
        illum.color = Color(0.0f, 0.0f, 0.0f);
    }

  // Compute the brightness-color of this light using inverse squared distance
  // to light source (i.e. 1/(d^2)), the color of this light source and the
  // intensity

  //设p多个点到点光源的距离为d_p，点光源的强度为i，颜色为c，则到达点p的强度（或“颜色”）c_p为：
  //c_p = (i / (d_p)^2) * c



  return illum;
}