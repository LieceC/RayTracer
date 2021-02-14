#pragma once

#include "Ray.hh"
#include "MaterialsParameters.h"

namespace RayTracer {
    class Object {
    public:
        /**
         * Compute the intersection between an object with a ray
         * @param ray the ray coming from the camera ot the sphere
         * @param point Return the first point of intersection in [point]
         * @return True if it has an intersection, false otherwise
         * */
        Object()= default;;
        Object(const RayTracer::Vec3& color, MaterialsParameters materialSpec) : color(color), materialSpec(materialSpec){};
        virtual bool intersect(Ray ray, RayTracer::Vec3 *point) const = 0;

        virtual RayTracer::Vec3 getNormal(RayTracer::Vec3 intersect_point) const = 0;

        /**
         * Get the materials specifications for this object
         * @return MaterialsParameters describing the attribute for the materials
         */
        MaterialsParameters getParam() {
            return this->materialSpec;
        }

        RayTracer::Vec3 getColor() {
            return this->color;
        }

    protected:
        //Does an object only have one color ??? HMMM
        RayTracer::Vec3 color;
        MaterialsParameters materialSpec{};
    };
}
