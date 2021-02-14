#pragma once
#include "Vec3.hh"

namespace SCENE {
    class Ray {
    public:
        Ray(IMAGE::Vec3 orig, IMAGE::Vec3 dir);
        IMAGE::Vec3 getOrig();
        IMAGE::Vec3 getDir();
    private:
        IMAGE::Vec3 orig;
        IMAGE::Vec3 dir;
    };
}
