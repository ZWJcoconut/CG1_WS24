// #include "light/light.h"
// #include "scene/scene.h"
// #include "shader/simpleshadowshader.h"

// // Constructor to initialize the SimpleShadowShader with the object's color
// SimpleShadowShader::SimpleShadowShader(Color const &objectColor) : objectColor(objectColor) {}

// Color SimpleShadowShader::shade(Scene const &scene, Ray const &ray) const {
//     // Initialize the final color to black
//     Color finalColor(0, 0, 0);

//     // Loop through all light sources in the scene
//     for (auto const &light : scene.lights()) {
//         // Get the illumination information from the light source for this ray
//         Light::Illumination illumination = light->illuminate(scene, ray);

//         // If the illumination color is black (meaning the point is in shadow), skip this light
//         if (illumination.color == Color(0, 0, 0)) {
//             continue;
//         }

//         // Calculate the combined color by adding the object's color and the illumination color
//         auto offsetPoint = objectColor + illumination.color;
        
//         // Accumulate the light contribution into the final color
//         finalColor += offsetPoint;
//     }

//     // Set a brightness threshold to prevent overexposure
//     float threshold = 2;
//     // Find the maximum component (r, g, or b) of the final color
//     float Component = std::max({finalColor.r, finalColor.g, finalColor.b});
    
//     // If the maximum component exceeds the threshold, scale down all color components proportionally
//     if (Component > threshold) {
//         finalColor.r /= Component;
//         finalColor.g /= Component;
//         finalColor.b /= Component;
//     }

//     // Return the computed final color for this point
//     return finalColor;
//     // return Color(0, 1, 0); // Uncomment this line to return a green color instead
// }


// #include "light/light.h"
// #include "scene/scene.h"
// #include "shader/simpleshadowshader.h"
// #include "common/ray.h"
// #include "light/pointlight.h"

// // Define a helper function to clamp each component of the color
// // Color clampColor(Color const &color, float min, float max) {
// //     return Color(
// //         std::max(min, std::min(color.r, max)),
// //         std::max(min, std::min(color.g, max)),
// //         std::max(min, std::min(color.b, max))
// //     );
// // }

// SimpleShadowShader::SimpleShadowShader(Color const &objectColor) : objectColor(objectColor) {}

// Color SimpleShadowShader::shade(Scene const &scene, Ray const &ray) const {
//     Color finalColor(0, 0, 0);

//     Vector3d surfacePoint = ray.origin + ray.direction * ray.length;

//     for (auto const &light : scene.lights()) {
//         auto pointLight = std::dynamic_pointer_cast<PointLight>(light);
//         if (!pointLight) {
//             continue;
//         }

//         Light::Illumination illumination = light->illuminate(scene, ray);
//         Vector3d offsetPoint = surfacePoint + illumination.direction * 1e-4f;
//         Ray shadowRay(offsetPoint, illumination.direction);
//         shadowRay.length = length(pointLight->getPosition() - surfacePoint);

//         if (!scene.findOcclusion(shadowRay)) {
//             Color lightContribution = illumination.color * objectColor;
//             finalColor += lightContribution;
//             //finalColor += clampColor(lightContribution, 0.0f, 1.0f);  // Ensure color stays within range
//         }
//     }

//     float threshold = 1.5f;  // Adjust threshold to prevent overexposure
//     float Component = std::max({finalColor.r, finalColor.g, finalColor.b});
//     if (Component > threshold) {
//         finalColor /= Component;  // Scale down final color to prevent overexposure
//     }

//     return finalColor;
// }


#include "light/light.h"
#include "scene/scene.h"
#include "shader/simpleshadowshader.h"
#include "common/ray.h"
#include "light/pointlight.h"   //Ensure PointLight header is included  , Make getPosition() available

SimpleShadowShader::SimpleShadowShader(Color const &objectColor) : objectColor(objectColor) {}

Color SimpleShadowShader::shade(Scene const &scene, Ray const &ray) const {
  // IMPLEMENT ME
  // loop over all light sources to check for visibility and multiply "light
  // strength" with this objects albedo (color)
  // 初始化最终颜色为黑色   Initialize final color to black
    Color finalColor(0, 0, 0);

    // 计算交点坐标  Calculate the intersection point
    Vector3d surfacePoint = ray.origin + ray.direction * ray.length;

    // 遍历场景中的每个光源  Iterate over each light source in the scene
    for (auto const &light : scene.lights()) {
        // 尝试将光源转换为 PointLight 类型  Attempt to cast the light to PointLight type
        auto pointLight = std::dynamic_pointer_cast<PointLight>(light);
        if (!pointLight) {
            continue; // 如果转换失败，跳过非 PointLight 类型的光源  Skip non-PointLight light sources
        }
        // 获取从交点指向光源的光照信息  Get the illumination information from the intersection point to the light source
        Light::Illumination illumination = light->illuminate(scene, ray);

        // 创建从交点指向光源的阴影光线，带有少量偏移以防止自相交 Create a shadow ray from the intersection point to the light source,
        // with a small offset to prevent self-intersection
        Vector3d offsetPoint = surfacePoint + illumination.direction * 1e-4f;
        Ray shadowRay(offsetPoint, illumination.direction);

        // 使用 getPosition() 获取光源位置，并计算阴影光线的长度  Use getPosition() to get the light source position and calculate the shadow ray length
        shadowRay.length = length(pointLight->getPosition() - surfacePoint);

        // 检查是否有物体阻挡阴影光线  Check if the shadow ray is blocked by any object
        if (!scene.findOcclusion(shadowRay)) {
            // 没有遮挡的情况下，计算该光源对该点的颜色贡献   If not blocked, calculate the color contribution from this light source
            Color lightContribution = illumination.color * objectColor;
            finalColor += lightContribution;
        }
    }

        float threshold = 2.0f;  // Adjust threshold to prevent overexposure
        float Component = std::max({finalColor.r, finalColor.g, finalColor.b});
        if (Component > threshold) {
            finalColor /= Component;  // Scale down final color to prevent overexposure
        }

    return finalColor;
  //return Color(0, 1, 0);
}
