#pragma once
#include <cmath>
#include "../include/Vec3.hh"

/**
 * Compute the fresnel_coefficient for the Blinn–Phong_reflection_model
 * using the normal vector and the light vector
 * @param l_v the light vector normalized
 * @param n_v the normal vector to the intersection point
 * @param refract_ind eta coefficient of reflection for a specific material
 * @return the fresnel coefficient, between 0 and 1, 1 if the coefficient is too high
 */
float fresnel_coefficient(IMAGE::Vec3 l_v, IMAGE::Vec3 n_v, float refract_ind);