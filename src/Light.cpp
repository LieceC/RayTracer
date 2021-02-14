

#include "../include/Light.hh"

IMAGE::Vec3 LIGHTING::Light::atVector(IMAGE::Vec3 point) {
    return this->position - point;
}

LIGHTING::Light::Light(IMAGE::Vec3 RGB_Color, IMAGE::Vec3 position, float intensity) {
    this->RGB_color = RGB_Color;
    this->position = position;
    this->intensity = intensity;
}

float LIGHTING::Light::getIntensity() const {
    return intensity;
}

const IMAGE::Vec3 LIGHTING::Light::getRBGColor() const {
    return RGB_color;
}

const IMAGE::Vec3 LIGHTING::Light::getPosition() const {
    return position;
}
