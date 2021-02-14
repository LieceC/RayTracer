#pragma once
#include "Object.hh"
#include "Vec3.hh"

namespace SCENE {
    class Sphere : public Object {
    public:
        /**
         * Create a sphere object consisting of a [position] and a [radius] of a specific material [spec]
         * @param position
         * @param radius
         * @param spec The
         */
        Sphere(const IMAGE::Vec3& position,float radius,const IMAGE::Vec3& color_Vec,MaterialsParameters spec);
        /**
         * Compute the intersection between an object with a ray
         * @param ray the ray coming from the camera ot the sphere
         * @param point Return the first point of intersection in [point]
         * @return True if it has an intersection, false otherwise
         */
        bool intersect(Ray ray,IMAGE::Vec3 *point) const;
        IMAGE::Vec3 getNormal(IMAGE::Vec3 intersect_point) const;
    private:
        IMAGE::Vec3 position;
        float radius;
    };
}
