

#include "../include/Sphere.hh"
#include <cmath>
bool SCENE::Sphere::intersect(SCENE::Ray ray,IMAGE::Vec3 *point) const {
    IMAGE::Vec3 oc = ray.getOrig() - this->position;
    float a = ray.getDir().dot(ray.getDir());
    float b = 2.0f * oc.dot(ray.getDir());
    float c = oc.dot(oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;
    if (discriminant>=0) {
        float t = (-b - std::sqrt(discriminant)) / (2*a);
        *point = ray.getOrig()+ray.getDir()*t;
        return true;
    }
    else return false;
}


SCENE::Sphere::Sphere(const IMAGE::Vec3& position, float radius,const IMAGE::Vec3& color_Vec,MaterialsParameters spec) : position(position),radius(radius),Object(color_Vec,spec) {}

IMAGE::Vec3 SCENE::Sphere::getNormal(IMAGE::Vec3 intersect_point) const {
    return (intersect_point - this->position)/this->radius;
}
