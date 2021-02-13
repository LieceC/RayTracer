#pragma once
#include <iostream>

namespace IMAGE{
    class Vec3 {
		public:
		Vec3();
		Vec3(float x,float y, float z);
        Vec3(const IMAGE::Vec3 &v);

        Vec3(Vec3 *pVec3);

        Vec3 operator*(const float &l) const;
        Vec3 operator*(const Vec3 &v) const;
        Vec3 operator/(const float &l) const;
        Vec3 operator-(const Vec3 &v) const;
        Vec3 operator+(const Vec3 &v) const;
        float operator[](int index);
        float operator[](int index) const;
        float dot(const Vec3& v) const;
        Vec3 cross(const Vec3& v) const;
        float norm() const;
    private:
		float m_data[3]{};
    };
}
std::ostream& operator<< (std::ostream &out, const IMAGE::Vec3& v);



