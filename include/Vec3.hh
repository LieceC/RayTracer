#pragma once
#include <iostream>

namespace IMAGE{
    class Vec3 {
		public:
		Vec3();
		Vec3(float x,float y, float z);
        Vec3 operator*(const float &l) const;
        /**
         * Implement a point to point multiplication of vectors !!!!
         * @param v
         * @return the point to point multiplication in 2 vector
         */
        Vec3 operator*(const Vec3 &v) const;
        Vec3 operator/(const float &l) const;
        Vec3 operator-(const Vec3 &v) const;
        Vec3 operator+(const Vec3 &v) const;
        Vec3& operator=(const Vec3 &v);
        float operator[](int index) const;
        float dot(const Vec3& v) const;
        Vec3 cross(const Vec3& v) const;
        float norm() const;
    private:
		float x,y,z;
    };
}
std::ostream& operator<< (std::ostream &out, const IMAGE::Vec3& v);



