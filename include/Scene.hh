#pragma once
#include "Camera.hh"
#include "Object.hh"
#include "Light.hh"
#include "Image.hh"
#include <vector>

class Scene {
public:
    Scene(RayTracer::Camera  camera, RayTracer::Object *object, RayTracer::Vec3 background_color);
    Scene(RayTracer::Camera  camera, RayTracer::Object *object);
    Scene(RayTracer::Camera  camera);
    void render(int image_width, int image_height, int needed_bounce = 0);
    RayTracer::Vec3 computeLightningAndShadows(RayTracer::Object *object, RayTracer::Vec3 intersect_point, int bounce_remaining = 0);
    void addObject(RayTracer::Object *object);
    void removeLastObject();
    void removeObject(int index);
    void addLightSource(RayTracer::Light *light_source);
    void removeLightSource(int index);
    void clearLightSources();
    void clearScene();
private:
    RayTracer::Camera camera;
    std::vector<RayTracer::Object*> objects;
    std::vector<RayTracer::Light*> light_sources;
    //For now, we'll suppose that this is a constant.
    float ambiantStrengthScene = 0.1;
    RayTracer::Vec3 background_color = {0, 0, 0};

    void clearObjects();
};
