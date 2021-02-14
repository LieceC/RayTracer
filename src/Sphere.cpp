#include "../include/Sphere.hh"
#include <cmath>

bool RayTracer::Sphere::intersect(RayTracer::Ray ray, RayTracer::Vec3 *point) const {
    RayTracer::Vec3 oc = ray.getOrig() - this->position;
    float a = ray.getDir().dot(ray.getDir());
    float b = 2.0f * oc.dot(ray.getDir());
    float c = oc.dot(oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;
    if (discriminant >= 0) {
        if (point != nullptr) {
            float t = (-b - std::sqrt(discriminant)) / (2 * a);
            *point = ray.getOrig() + ray.getDir() * t;
        }
        return true;
    } else return false;
}


RayTracer::Sphere::Sphere(const RayTracer::Vec3 &position, float radius, const RayTracer::Vec3 &color_Vec, MaterialsParameters spec)
        : position(position), radius(radius), Object(color_Vec, spec) {}

RayTracer::Vec3 RayTracer::Sphere::getNormal(RayTracer::Vec3 intersect_point) const {
    return (intersect_point - this->position) / this->radius;
}
