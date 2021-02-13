

#include "../include/Camera.hh"

SCENE::Ray SCENE::Camera::pixelToRay(int pixelX, int pixelY, int size_x, int size_y) const {
    float v = (static_cast<float>(pixelY) / static_cast<float>(size_y - 1)) * this->sensor_size_y - this->sensor_size_y / 2;
    float u = (static_cast<float>(pixelX) / static_cast<float>(size_x - 1)) * this->sensor_size_x - this->sensor_size_x / 2;
    IMAGE::Vec3 const zCam = (this->pos - this->target);
    IMAGE::Vec3 zCam2 = zCam / zCam.norm();
    IMAGE::Vec3 const xCam = zCam2.cross(this->up);
    IMAGE::Vec3 xCam2 = xCam / xCam.norm();
    IMAGE::Vec3 const yCam = zCam2.cross(xCam2);
    IMAGE::Vec3 yCam2 = yCam / yCam.norm();
    IMAGE::Vec3 vecX = xCam2 * u * this->sensor_size_x;
    IMAGE::Vec3 vecY = yCam2 * v * this->sensor_size_y;
    IMAGE::Vec3 vecZ = zCam2 * -this->focal;
    IMAGE::Vec3 Ca = vecX + vecY + vecZ;
    return {pos, Ca };
}
SCENE::Camera::Camera(float focal, float sensor_size_x,float sensor_size_y, const IMAGE::Vec3& pos, const IMAGE::Vec3& target, const IMAGE::Vec3& vertical_dir) {
    this->focal = focal;
    this->sensor_size_x = sensor_size_x;
    this->sensor_size_x = sensor_size_y;
    this->pos = pos;
    this->target = target;
    this->up = vertical_dir;
}
const IMAGE::Vec3 &SCENE::Camera::getPos() const {
    return pos;
}

SCENE::Camera::Camera() = default;
