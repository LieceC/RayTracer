#pragma once
#include "Vec3.hh"

namespace LIGHTING {
    class Light {
    public:
        float getIntensity() const;
        const IMAGE::Vec3 &getRgbIntensity() const;
        const IMAGE::Vec3 &getPosition() const;
        Light(IMAGE::Vec3 RGB_intensity,IMAGE::Vec3 position,IMAGE::Vec3 direction,float intensity);
        IMAGE::Vec3 atVector(IMAGE::Vec3 const point);
    private:
        float intensity;
        IMAGE::Vec3 RGB_intensity;
        IMAGE::Vec3 position;
    };
}
