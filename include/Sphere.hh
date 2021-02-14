#pragma once
#include "Object.hh"
#include "Vec3.hh"

namespace RayTracer {
    class Sphere : public Object {
    public:
        /**
         * Create a sphere object consisting of a [position] and a [radius] of a specific material [spec]
         * @param position
         * @param radius
         * @param spec The
         */
        Sphere(const RayTracer::Vec3& position, float radius, const RayTracer::Vec3& color_Vec, MaterialsParameters spec);
        /**
         * Compute the intersection between an object with a ray
         * @param ray the ray coming from the camera ot the sphere
         * @param point Return the first point of intersection in [point]
         * @return True if it has an intersection, false otherwise
         */
        bool intersect(Ray ray, RayTracer::Vec3 *point) const;
        RayTracer::Vec3 getNormal(RayTracer::Vec3 intersect_point) const;
    private:
        RayTracer::Vec3 position;
        float radius;
    };
}
