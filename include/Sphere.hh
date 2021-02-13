#pragma once
#include "Object.hh"
#include "Vec3.hh"

namespace SCENE {
    class Sphere : public Object {
    public:
        Sphere(const IMAGE::Vec3& position,float radius,MaterialsParameters *spec);
        bool intersect(const Ray &ray,IMAGE::Vec3 *point) const;
        IMAGE::Vec3 getNormal(IMAGE::Vec3 intersect_point) const;
    private:
        IMAGE::Vec3 position;
        float radius;
    };
}
