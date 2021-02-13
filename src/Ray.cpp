

#include "../include/Ray.hh"

const IMAGE::Vec3 &SCENE::Ray::getOrig() const {
    return orig;
}

const IMAGE::Vec3 &SCENE::Ray::getDir() const {
    return dir;
}

SCENE::Ray::Ray(IMAGE::Vec3 orig, IMAGE::Vec3 dir) {
    this->dir = dir;
    this->orig = orig;
}
