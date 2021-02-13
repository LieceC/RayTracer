#include "../include/Vec3.hh"
#include <cmath>
#include <iostream>

using namespace IMAGE;

IMAGE::Vec3::Vec3() {
    this->m_data[0] = 0.0f;
    this->m_data[1] = 0.0f;
    this->m_data[2] = 0.0f;
}

IMAGE::Vec3::Vec3(float x, float y, float z) {
    this->m_data[0] = x;
    this->m_data[1] = y;
    this->m_data[2] = z;
}

IMAGE::Vec3::Vec3(const IMAGE::Vec3 &v) {
    this->m_data[0] = v.m_data[0];
    this->m_data[1] = v.m_data[1];
    this->m_data[2] = v.m_data[2];
}

float Vec3::operator[](int index) {
    return this->m_data[index];
}

float Vec3::operator[](int index) const {
    return this->m_data[index];
}

IMAGE::Vec3 IMAGE::Vec3::operator*(const float &l) const {
    return {this->m_data[0] * l, this->m_data[1] * l, this->m_data[2] * l};
}

IMAGE::Vec3 IMAGE::Vec3::operator-(const IMAGE::Vec3 &v) const {
    return {this->m_data[0] - v[0], this->m_data[1] - v[1], this->m_data[2] - v[2]};
}

float Vec3::dot(const Vec3 &v) const {
    return m_data[0] * v[0] +
           m_data[1] * v[1] +
           m_data[2] * v[2];
}

float Vec3::norm() const {
    return std::sqrt(m_data[0] * m_data[0] +
           m_data[1] * m_data[1] +
           m_data[2] * m_data[2]);
}

IMAGE::Vec3 Vec3::cross(const Vec3 &v) const {
        float x_cross = m_data[1]*v.m_data[2] - m_data[2]*v.m_data[1];
        float y_cross = m_data[2]*v.m_data[0] - m_data[0]*v.m_data[2];
        float z_cross = m_data[0]*v.m_data[1] - m_data[1]*v.m_data[0];
        return { x_cross, y_cross, z_cross };
}

Vec3 Vec3::operator+(const Vec3 &v) const {
    return {this->m_data[0] + v[0], this->m_data[1] + v[1], this->m_data[2] + v[2]};
}

Vec3::Vec3(Vec3 *pVec3) {
    this->m_data[0] = pVec3->m_data[0];
    this->m_data[1] = pVec3->m_data[1];
    this->m_data[2] = pVec3->m_data[2];
}

Vec3 Vec3::operator/(const float &l) const {
    return {this->m_data[0] / l, this->m_data[1] / l, this->m_data[2] / l};
}

Vec3 Vec3::operator*(const Vec3 &v) const {
    return {this->m_data[0]*v.m_data[0],this->m_data[1]*v.m_data[1],this->m_data[1]*v.m_data[1]};
}

std::ostream &operator<<(std::ostream &out, const Vec3 &v) {
    out << v[0] << " " << v[1] << " " << v[2];
    return out;
}

