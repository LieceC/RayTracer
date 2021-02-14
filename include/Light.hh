#pragma once
#include "Vec3.hh"

namespace RayTracer {
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
        RayTracer::Vec3 getRBGColor() const;
        RayTracer::Vec3 getPosition() const;
        /**
         * Create a light with the color [RGB_Color] at the position [position] with an intensity [intensity].
         * @param RGB_Color The Vec3 colors vector of the light.
         * @param position  The position of the light in the scene coordinates
         * @param intensity The intensity of the light
         */
        Light(RayTracer::Vec3 RGB_Color, RayTracer::Vec3 position, float intensity) : RGB_color(RGB_Color), position(position), intensity(intensity){};
        /**
         * Create the vector coming from the 3D point [point] to the light direction
         * @param point A 3D point in the scene coordinate
         * @return A vector pointing to the light from [point]
         */
        RayTracer::Vec3 atVector(RayTracer::Vec3 point);
    private:
        float intensity;
        RayTracer::Vec3 RGB_color;
        RayTracer::Vec3 position;
    };
}
