#ifndef RAYTRACER_UTILS_H
#define RAYTRACER_UTILS_H
#include <cmath>
#include "../include/Vec3.hh"

float fresnel_coefficient(IMAGE::Vec3 l_v, IMAGE::Vec3 n_v, float refract_ind);


#endif //RAYTRACER_UTILS_H
