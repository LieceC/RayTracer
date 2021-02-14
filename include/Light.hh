#pragma once
#include "Vec3.hh"

namespace LIGHTING {
    class Light {
    public:
        /**
         * Get the intensity of the light
         * @return A float between 0 and 1
         */
        float getIntensity() const;
        /**
         * Return the color of the light
         * @return Vec3 Describing the color of the light
         */
        const IMAGE::Vec3 getRBGColor() const;
        const IMAGE::Vec3 getPosition() const;
        /**
         * Create a light with the color [RGB_Color] at the position [position] with an intensity [intensity].
         * @param RGB_Color The Vec3 colors vector of the light.
         * @param position  The position of the light in the scene coordinates
         * @param intensity The intensity of the light
         */
        Light(IMAGE::Vec3 RGB_Color, IMAGE::Vec3 position, float intensity);
        /**
         * Create the vector coming from the 3D point [point] to the light direction
         * @param point A 3D point in the scene coordinate
         * @return A vector pointing to the light from [point]
         */
        IMAGE::Vec3 atVector(IMAGE::Vec3 point);
    private:
        float intensity;
        IMAGE::Vec3 RGB_color;
        IMAGE::Vec3 position;
    };
}
