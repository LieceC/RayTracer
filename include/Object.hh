#pragma once
#include "Ray.hh"
#include "MaterialsParameters.h"

namespace SCENE {
    class Object {
    public:
        /**
         * Compute the intersection between an object with a ray
         * @param ray the ray coming from the camera ot the sphere
         * @param point Return the first point of intersection in [point]
         * @return True if it has an intersection, false otherwise
         * */
        virtual bool intersect(Ray ray,IMAGE::Vec3 *point) const = 0;
        virtual IMAGE::Vec3 getNormal(IMAGE::Vec3 intersect_point) const = 0;
        /**
         * Get the materials specifications for this object
         * @return MaterialsParameters describing the attribute for the materials
         */
        MaterialsParameters getParam() {
            return this->materialSpec;
        }
        IMAGE::Vec3 getColor() {
            return this->color;
        }
    protected:
        //Does an object only have one color ??? HMMM
        IMAGE::Vec3 color;
        MaterialsParameters materialSpec;
    };
}
