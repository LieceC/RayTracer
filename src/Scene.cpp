#include "../include/Scene.hh"
#include "../include/utils.h"


//TODO
void Scene::render(int image_width, int image_height, int needed_bounce) {
    IMAGE::Image img = IMAGE::Image(image_width, image_height);
    for (int row = 0; row < image_height; row++) {
        for (int col = 0; col < image_width; col++) {
            SCENE::Ray r = this->camera.pixelToRay(row, col, image_width, image_height);
            for (const auto &v : objects) {
                IMAGE::Vec3 point;
                //TODO Only take into account the nearest Intersection
                if (v->intersect(r, &point)) {
                    IMAGE::Vec3 color = computeLightningAndShadows(v, point,needed_bounce);
                    img.setPixel(row, col, color[0], color[1], color[2]);
                } else {
                    img.setPixel(row, col, background_color[0], background_color[1], background_color[2]);
                }
            }
        }
    }
    img.save("test.ppm");
}

IMAGE::Vec3 Scene::computeLightningAndShadows(SCENE::Object *object,
                                              const IMAGE::Vec3 &intersect_point, int bounce_remaining) {
    //total color
    IMAGE::Vec3 colorT = new IMAGE::Vec3();
    // Ambient color
    IMAGE::Vec3 colorA = object->getParam().color * ambiantStrength * object->getParam().ka;
    // Diffuse color
    IMAGE::Vec3 colorD = new IMAGE::Vec3(0, 0, 0);
    // Specular color
    IMAGE::Vec3 colorS = new IMAGE::Vec3(0, 0, 0);
    IMAGE::Vec3 normal_vector = object->getNormal(intersect_point);
    IMAGE::Vec3 camera_vector = (camera.getPos() - intersect_point);
    camera_vector = camera_vector / camera_vector.norm();
    for (const auto &v : light_sources) {
        bool inShadows = false;
        IMAGE::Vec3 vec_to_light = (v->getPosition() - intersect_point);
        vec_to_light = vec_to_light / vec_to_light.norm();
        SCENE::Ray r(intersect_point, vec_to_light);
        for (const auto *v2 : this->objects) {
            if (v2 != object && v2->intersect(r, nullptr)) {
                inShadows = true;
                break;
            }
        }
        if (not inShadows) {
            IMAGE::Vec3 light_dir = v->atVector(intersect_point);
            light_dir = light_dir / light_dir.norm();
            IMAGE::Vec3 half_vector = (light_dir + camera_vector) / (light_dir + camera_vector).norm();
            float fCoeff = fresnel_coefficient(light_dir, normal_vector, object->getParam().refract_ind);
            if (bounce_remaining > 0) {
                IMAGE::Vec3 reflected_ray_vec = light_dir - normal_vector * 2 * normal_vector.dot(light_dir);
                SCENE::Ray r_ref(intersect_point, reflected_ray_vec);
                IMAGE::Vec3 point;
                //TODO Only take into account the nearest Intersection
                for (const auto &o : objects) {
                    if (o->intersect(r_ref, &point)) {
                        colorT = colorT + computeLightningAndShadows(o, point, bounce_remaining - 1) * fCoeff;
                    }
                }
            }
            colorD = colorD + (object->getParam().color * object->getParam().kd *
                               std::max(0.0f, normal_vector.dot(light_dir)) * v->getIntensity() *
                               v->getRgbIntensity());

            float temp = std::pow(std::max(0.0f, normal_vector.dot(half_vector)), object->getParam().shininess);
            colorS = colorS + (object->getParam().color * v->getIntensity() * fCoeff * temp * v->getRgbIntensity());
        }
    }
    colorT = colorA + colorD + colorS;
    return {std::min(colorT[0], 255.0f), std::min(colorT[1], 255.0f), std::min(colorT[2], 255.0f)};
}
Scene::Scene(const SCENE::Camera&
             camera, SCENE::Object *object) {
    this->camera = camera;
    this->addObject(object);
}

Scene::Scene(const SCENE::Camera&
             camera, SCENE::Object *object, const IMAGE::Vec3&
             background_color) {
    this->camera = camera;
    this->addObject(object);
    this->background_color = background_color;
}

Scene::Scene(const SCENE::Camera&
             camera) {
    this->camera = camera;
}

void Scene::addObject(SCENE::Object *object) {
    this->objects.push_back(object);
}

void Scene::removeLastObject() {
    this->objects.pop_back();
}

void Scene::removeObject(int index) {
    this->objects.erase(this->objects.begin()+index);
}

void Scene::clearObjects() {
    this->objects.clear();
}
void Scene::clearScene() {
    this->clearLightSources();
    this->clearObjects();
}

void Scene::addLightSource(LIGHTING::Light *light_source) {
    this->light_sources.push_back(light_source);
}

void Scene::removeLightSource(int index) {
    this->light_sources.erase(this->light_sources.begin()+index);
}

void Scene::clearLightSources() {
    this->light_sources.clear();
}
