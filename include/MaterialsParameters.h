#pragma once

struct MaterialsParameters {
    float kd{}; //between 0 and 1
    float ka{};
    float refract_ind{};
    float shininess{};
    IMAGE::Vec3 color{}; //Color vector of the object;
};