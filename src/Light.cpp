

#include "../include/Light.hh"

IMAGE::Vec3 LIGHTING::Light::atVector(IMAGE::Vec3 const point) {
    return this->position - point;
}

LIGHTING::Light::Light(IMAGE::Vec3 RGB_intensity, IMAGE::Vec3 position, IMAGE::Vec3 direction,float intensity) {
    this->RGB_intensity = RGB_intensity;
    this->position = position;
    this->intensity = intensity;
}

float LIGHTING::Light::getIntensity() const {
    return intensity;
}

const IMAGE::Vec3 &LIGHTING::Light::getRgbIntensity() const {
    return RGB_intensity;
}

const IMAGE::Vec3 &LIGHTING::Light::getPosition() const {
    return position;
}
