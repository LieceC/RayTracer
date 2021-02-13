#pragma once
#include "Ray.hh"
#include "MaterialsParameters.h"

namespace SCENE {
    class Object {
    public:
        virtual bool intersect(const Ray &ray,IMAGE::Vec3 *point) const = 0;
        virtual IMAGE::Vec3 getNormal(IMAGE::Vec3 intersect_point) const = 0;
        MaterialsParameters getParam() const {
            return *this->materialSpec;
        }
    protected:
        MaterialsParameters *materialSpec{};
    };
}
