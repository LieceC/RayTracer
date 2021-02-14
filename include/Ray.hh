#pragma once
#include "Vec3.hh"

namespace RayTracer {
    class Ray {
    public:
        Ray(RayTracer::Vec3 orig, RayTracer::Vec3 dir);
        RayTracer::Vec3 getOrig();
        RayTracer::Vec3 getDir();
    private:
        RayTracer::Vec3 orig;
        RayTracer::Vec3 dir;
    };
}
