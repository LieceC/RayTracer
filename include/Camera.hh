#pragma once

#include "Vec3.hh"
#include "Ray.hh"

namespace SCENE {
    class Camera {
    public:
        Camera();
        Camera(float focal, float sensor_size_x,float sensor_size_y, const IMAGE::Vec3& pos, const IMAGE::Vec3& target, const IMAGE::Vec3& vertical_dir);
        SCENE::Ray pixelToRay(int pixelX, int pixelY, int width, int height) const;
        const IMAGE::Vec3 &getPos() const;

    private:
        float focal{};
        float sensor_size_x{};
        float sensor_size_y{};
        IMAGE::Vec3 pos;
        IMAGE::Vec3 target;
        IMAGE::Vec3 up;
    };
}
