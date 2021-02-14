#include "../include/Vec3.hh"
#include "../include/utils.h"
#include <cmath>

float fresnel_coefficient(RayTracer::Vec3 l_v, RayTracer::Vec3 n_v, float refract_ind) {
    float eta_2 = std::pow(refract_ind, 2);
    float cos_theta = l_v.dot(n_v);
    float sin_2 = 1 - std::pow(cos_theta, 2);
    float ci_2 = eta_2 - sin_2;
    if (ci_2 < 0) return 1.0; // total iternal illumination
    float ci = std::sqrt(ci_2);
    float f_s = std::pow((cos_theta - ci) / (cos_theta + ci), 2);
    float f_p = std::pow((eta_2 * cos_theta - ci) / eta_2 * cos_theta + ci, 2);
    return std::min((f_s + f_p) / 2, 1.0f);
}