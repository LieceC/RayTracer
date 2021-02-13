#pragma once
#include "Camera.hh"
#include "Object.hh"
#include "Light.hh"
#include "Image.hh"
#include <vector>

class Scene {
public:
    Scene(const SCENE::Camera& camera,SCENE::Object *object, const IMAGE::Vec3& background_color);
    Scene(const SCENE::Camera& camera,SCENE::Object *object);
    Scene(const SCENE::Camera& camera);
    void render(int image_width, int image_height, int needed_bounce = 0);
    IMAGE::Vec3 computeLightningAndShadows(SCENE::Object *object,const IMAGE::Vec3 &intersect_point,int bounce_remaining = 0);
    void addObject(SCENE::Object *object);
    void removeLastObject();
    void removeObject(int index);
    void clearScene();
    void addLightSource(LIGHTING::Light *light_source);
    void removeLightSource(int index);
    void clearLightSources();
private:
    SCENE::Camera camera;
    std::vector<SCENE::Object*> objects;
    std::vector<LIGHTING::Light*> light_sources;
    //For now, we'll suppose that this is a constant.
    float ambiantStrength = 0.1;
    IMAGE::Vec3 background_color = {0,0,0};

    void clearObjects();
};
