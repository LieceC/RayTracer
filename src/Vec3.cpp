#include "../include/Vec3.hh"
#include <cmath>
#include <iostream>

using namespace RayTracer;

RayTracer::Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}

RayTracer::Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

float Vec3::operator[](int index) const {
    switch (index) {
        case 0 :
            return x;
        case 1 :
            return y;
        case 2 :
            return z;
        default :
            return -1;
    }
}

RayTracer::Vec3 RayTracer::Vec3::operator*(const float &l) const {
    return {this->x * l, this->y * l, this->z * l};
}

Vec3 Vec3::operator*(const Vec3 &v) const {
    return {this->x * v.x, this->y * v.y, this->z * v.z};
}

RayTracer::Vec3 RayTracer::Vec3::operator-(const RayTracer::Vec3 &v) const {
    return {this->x - v.x, this->y - v.y, this->z - v.z};
}


Vec3 Vec3::operator+(const Vec3 &v) const {
    return {this->x + v.x, this->y + v.y, this->z + v.z};
}

Vec3 Vec3::operator/(const float &l) const {
    return {this->x / l, this->y / l, this->z / l};
}

Vec3 &Vec3::operator=(const Vec3 &v) {
    if (this == &v)
        return *this;
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    return *this;
}

float Vec3::dot(const Vec3 &v) const {
    return x * v.x +
           y * v.y +
           z * v.z;
}

float Vec3::norm() const {
    return std::sqrt(x * x +
                     y * y +
                     z * z);
}

RayTracer::Vec3 Vec3::cross(const Vec3 &v) const {
    float x_cross = y * v.z - z * v.y;
    float y_cross = z * v.x - x * v.z;
    float z_cross = x * v.y - y * v.x;
    return {x_cross, y_cross, z_cross};
}

std::ostream &operator<<(std::ostream &out, const Vec3 &v) {
    out << v[0] << " " << v[1] << " " << v[2];
    return out;
}

