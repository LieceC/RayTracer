#include "../include/Light.hh"

RayTracer::Vec3 RayTracer::Light::atVector(RayTracer::Vec3 point) {
    return this->position - point;
}

float RayTracer::Light::getIntensity() const {
    return intensity;
}

RayTracer::Vec3 RayTracer::Light::getRBGColor() const {
    return RGB_color;
}

RayTracer::Vec3 RayTracer::Light::getPosition() const {
    return position;
}
