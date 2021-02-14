#include "../include/Camera.hh"

RayTracer::Camera::Camera(float focal, float sensor_size_x, float sensor_size_y, RayTracer::Vec3 pos, RayTracer::Vec3 target,
                          RayTracer::Vec3 vertical_dir) : focal(focal), sensor_size_x(sensor_size_x),
                                                          sensor_size_y(sensor_size_y), pos(pos), target(target),
                                                          up(vertical_dir) {}

RayTracer::Vec3 RayTracer::Camera::getPos() const {
    return pos;
}

RayTracer::Camera::Camera() = default;


RayTracer::Ray RayTracer::Camera::pixelToRay(int pixelX, int pixelY, int size_x, int size_y) const {
    float u = (static_cast<float>(pixelX) / static_cast<float>(size_x - 1)) * this->sensor_size_x -
              this->sensor_size_x / 2;
    float v = (static_cast<float>(pixelY) / static_cast<float>(size_y - 1)) * this->sensor_size_y -
              this->sensor_size_y / 2;
    RayTracer::Vec3 zCam = (this->pos - this->target);
    RayTracer::Vec3 zCam2 = zCam / zCam.norm();
    RayTracer::Vec3 xCam = zCam2.cross(this->up);
    RayTracer::Vec3 xCam2 = xCam / xCam.norm();
    RayTracer::Vec3 yCam = zCam2.cross(xCam2);
    RayTracer::Vec3 yCam2 = yCam / yCam.norm();

    RayTracer::Vec3 vecX = xCam2 * u * this->sensor_size_x;
    RayTracer::Vec3 vecY = yCam2 * v * this->sensor_size_y;
    RayTracer::Vec3 vecZ = zCam2 * -this->focal;

    RayTracer::Vec3 Ca = vecX + vecY + vecZ;
    return {this->getPos(), Ca};
}