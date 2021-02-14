#include "../include/Ray.hh"

RayTracer::Vec3 RayTracer::Ray::getOrig() {
    return orig;
}

RayTracer::Vec3 RayTracer::Ray::getDir() {
    return dir;
}

RayTracer::Ray::Ray(RayTracer::Vec3 orig, RayTracer::Vec3 dir) : dir(dir), orig(orig) {}
