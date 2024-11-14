#include "scene/scene.h"
#include "shader/refractionshader.h"
#include <cmath>
#include <iostream>

RefractionShader::RefractionShader(float indexInside, float indexOutside) 
    : indexInside(indexInside), indexOutside(indexOutside) {}

Color RefractionShader::shade(Scene const &scene, Ray const &ray) const {
    Vector3d normal = ray.normal;
    Vector3d incidentRay = ray.direction;

    // 判断光线是进入还是离开介质
    float eta;
    bool entering = dotProduct(incidentRay, normal) < 0;
    if (entering) {
        eta = indexOutside / indexInside;
    } else {
        eta = indexInside / indexOutside;
        normal = -normal;  // 如果离开介质，翻转法向量
    }

    float cosTheta = -dotProduct(incidentRay, normal);
    float sin2Theta = 1.0f - cosTheta * cosTheta;
    float sin2Phi = eta * eta * sin2Theta;

    // 检查是否发生全内反射
    if (sin2Phi > 1.0f) {
        std::cout << "Total internal reflection occurred." << std::endl;
        return Color(0.0f, 0.0f, 0.0f);
    }

    // 计算折射角的余弦值
    float cosPhi = std::sqrt(1.0f - sin2Phi);

    // 使用 Snell's Law 计算折射方向
    Vector3d refractionDirection = eta * incidentRay + (eta * cosTheta - cosPhi) * normal;
    refractionDirection = normalized(refractionDirection);

    // 创建一个微小的偏移量，避免自相交
    Vector3d offsetOrigin = ray.origin + refractionDirection * 1e-4f;

    // 创建折射光线
    Ray refractedRay(offsetOrigin, refractionDirection);

    // 设置折射光线的剩余反弹次数，防止无限递归
    refractedRay.setRemainingBounces(ray.getRemainingBounces() - 1);

    // 递归追踪折射光线并获取颜色
    Color refractedColor = scene.traceRay(refractedRay);

    return refractedColor;
}

// 实现 isTransparent 函数
bool RefractionShader::isTransparent() const {
    return true;
}

/*
 * 公式推导:
 * 根据斯涅尔定律: η₁ * sin(θ) = η₂ * sin(φ)
 * cos(θ) = -dotProduct(incidentRay, normal)
 * 我们计算 t（折射方向）为:
 * t = η * r + (η * cos(θ) - cos(φ)) * n
 * 其中:
 * η = η₁ / η₂
 * cos(φ) = sqrt(1 - η² * (1 - cos²(θ)))
 */
