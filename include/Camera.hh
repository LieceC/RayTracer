#pragma once

#include "Vec3.hh"
#include "Ray.hh"

namespace RayTracer {
    class Camera {
    public:
        Camera();
        /**
         * Create a camera with a a focal_length of [focal], the size of its sensor is [sensor_size_x*sensor_size_y],
         * at the position [pos] in x_y_z
         * @param focal The focal length
         * @param sensor_size_x The wideness of the sensor
         * @param sensor_size_y The height of the sensor
         * @param pos The 3D point position of the camera
         * @param target The 3D point the camera is oriented to
         * @param vertical_dir The vertical orientation of the camera
         */
        Camera(float focal, float sensor_size_x, float sensor_size_y, RayTracer::Vec3 pos, RayTracer::Vec3 target, RayTracer::Vec3 vertical_dir);
        /**
         * Create a ray starting from the camera to the [pixelX,pixelY] position in its local coordinates, translate it
         * into world coordinates and return the corresponding ray in a 3D referendum
         * @param pixelX The row position of the pixel in the image to render
         * @param pixelY The column position of the pixel in the image to render
         * @param width The width of the image to render
         * @param height The height of the image to render
         * @return A ray from the camera passing by [pixelX,pixelY] in the world coordinates
         */
        RayTracer::Ray pixelToRay(int pixelX, int pixelY, int width, int height) const;
        /**
         * Return the 3D position where the camera is placed.
         * @return
         */
        RayTracer::Vec3 getPos() const;

    private:
        float focal{};
        float sensor_size_x{};
        float sensor_size_y{};
        RayTracer::Vec3 pos;
        RayTracer::Vec3 target;
        /**
         * Lock the camera in the longitudinal axe
         */
        RayTracer::Vec3 up;
    };
}
