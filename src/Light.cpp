

#include "../include/Light.hh"

IMAGE::Vec3 LIGHTING::Light::atVector(IMAGE::Vec3 point) {
    return this->position - point;
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
