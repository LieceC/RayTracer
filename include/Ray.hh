#pragma once
#include "Vec3.hh"

namespace SCENE {
    class Ray {
    public:
        Ray(IMAGE::Vec3 orig, IMAGE::Vec3 dir);
        const IMAGE::Vec3 &getOrig() const;
        const IMAGE::Vec3 &getDir() const;
    private:
        IMAGE::Vec3 orig;
        IMAGE::Vec3 dir;
    };
}
