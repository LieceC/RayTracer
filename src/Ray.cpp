

#include "../include/Ray.hh"

IMAGE::Vec3 SCENE::Ray::getOrig() {
    return orig;
}

IMAGE::Vec3 SCENE::Ray::getDir() {
    return dir;
}

SCENE::Ray::Ray(IMAGE::Vec3 orig, IMAGE::Vec3 dir) : dir(dir), orig(orig) {}
