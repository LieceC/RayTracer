#include "../include/Camera.hh"

SCENE::Camera::Camera(float focal, float sensor_size_x, float sensor_size_y, IMAGE::Vec3 pos, IMAGE::Vec3 target,
                      IMAGE::Vec3 vertical_dir) : focal(focal), sensor_size_x(sensor_size_x),
                                                  sensor_size_y(sensor_size_y), pos(pos), target(target),
                                                  up(vertical_dir) {}

IMAGE::Vec3 SCENE::Camera::getPos() const {
    return pos;
}

SCENE::Camera::Camera() = default;


SCENE::Ray SCENE::Camera::pixelToRay(int pixelX, int pixelY, int size_x, int size_y) const {
    float u = (static_cast<float>(pixelX) / static_cast<float>(size_x - 1)) * this->sensor_size_x -
              this->sensor_size_x / 2;
    float v = (static_cast<float>(pixelY) / static_cast<float>(size_y - 1)) * this->sensor_size_y -
              this->sensor_size_y / 2;
    IMAGE::Vec3 zCam = (this->pos - this->target);
    IMAGE::Vec3 zCam2 = zCam / zCam.norm();
    IMAGE::Vec3 xCam = zCam2.cross(this->up);
    IMAGE::Vec3 xCam2 = xCam / xCam.norm();
    IMAGE::Vec3 yCam = zCam2.cross(xCam2);
    IMAGE::Vec3 yCam2 = yCam / yCam.norm();

    IMAGE::Vec3 vecX = xCam2 * u * this->sensor_size_x;
    IMAGE::Vec3 vecY = yCam2 * v * this->sensor_size_y;
    IMAGE::Vec3 vecZ = zCam2 * -this->focal;

    IMAGE::Vec3 Ca = vecX + vecY + vecZ;
    return {this->getPos(), Ca};
}