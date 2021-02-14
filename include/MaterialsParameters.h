#pragma once
struct MaterialsParameters {
    /**
     * Diffuse coefficient between 0 and 1
     */
    float kd;
    /**
     * Ambient coefficient between 0 and 1
     */
    float ka;
    /**
     * Refraction coefficient 0 and 1
     */
    float refract_ind;
    /**
     * Shininess coefficient between 1 and inf
     */
    float shininess;
};