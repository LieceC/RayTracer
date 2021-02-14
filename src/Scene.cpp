#include "../include/Scene.hh"
#include "../include/utils.h"


//TODO Only keep closest object intersect on a point
void Scene::render(int image_width, int image_height, int needed_bounce) {
    RayTracer::Image img(image_width, image_height);
    for (int row = 0; row < image_height; row++) {
        for (int col = 0; col < image_width; col++) {
            RayTracer::Ray r = this->camera.pixelToRay(row, col, image_width, image_height);
            RayTracer::Vec3 color;
            bool hasIntersect = false;
            for (const auto &v : objects) {
                RayTracer::Vec3 point;
                if (v->intersect(r, &point)) {
                    hasIntersect = true;
                    color = color + computeLightningAndShadows(v, point, needed_bounce);
                }
            }
            if(!hasIntersect){
                img.setPixel(row, col, background_color);
            } else img.setPixel(row, col, color);
        }
    }
    img.save("test.ppm");
}

RayTracer::Vec3 Scene::computeLightningAndShadows(RayTracer::Object *object,
                                                  RayTracer::Vec3 intersect_point, int bounce_remaining) {
    //total color
    RayTracer::Vec3 colorT(0, 0, 0);
    // Ambient color
    RayTracer::Vec3 colorA = object->getColor() * ambiantStrengthScene * object->getParam().ka;
    // Diffuse color
    RayTracer::Vec3 colorD(0, 0, 0);
    // Specular color
    RayTracer::Vec3 colorS(0, 0, 0);
    RayTracer::Vec3 normal_vector = object->getNormal(intersect_point);
    RayTracer::Vec3 camera_vector = (camera.getPos() - intersect_point);
    camera_vector = camera_vector / camera_vector.norm();
    for (const auto &v : light_sources) {
        bool inShadows = false;
        RayTracer::Vec3 vec_to_light = (v->getPosition() - intersect_point);
        vec_to_light = vec_to_light / vec_to_light.norm();
        RayTracer::Ray r(intersect_point, vec_to_light);
        for (const auto &v2 : this->objects) {
            if (v2 != object && v2->intersect(r, nullptr)) {
                inShadows = true;
                break;
            }
        }
        if (not inShadows) {
            RayTracer::Vec3 light_dir = v->atVector(intersect_point);
            light_dir = light_dir / light_dir.norm();
            RayTracer::Vec3 half_vector = (light_dir + camera_vector) / (light_dir + camera_vector).norm();
            float fresnelCoefficient = fresnel_coefficient(light_dir, normal_vector, object->getParam().refract_ind);
            if (bounce_remaining > 0) {
                RayTracer::Vec3 reflected_ray_vec = light_dir - normal_vector * 2 * normal_vector.dot(light_dir);
                RayTracer::Ray r_ref(intersect_point, reflected_ray_vec);
                RayTracer::Vec3 point;
                //TODO Only take into account the nearest Intersection
                for (const auto &o : objects) {
                    if (o->intersect(r_ref, &point)) {
                        colorT = colorT + computeLightningAndShadows(o, point, bounce_remaining - 1) * fresnelCoefficient;
                    }
                }
            }
            //TODO Should I multiply the ambient color for each object
            //colorA = object->getColor() * object->getParam().ka * v->getIntensity() * v->getRBGColor();
            colorD = colorD + (object->getColor() * object->getParam().kd *
                               std::max(0.0f, normal_vector.dot(light_dir)) * v->getIntensity() *
                               v->getRBGColor());

            float temp = std::pow(std::max(0.0f, normal_vector.dot(half_vector)), object->getParam().shininess);
            colorS = colorS + (object->getColor() * v->getIntensity() * fresnelCoefficient * temp * v->getRBGColor());
        }
    }
    colorT = colorA + colorD + colorS;
    return {std::min(colorT[0], 255.0f), std::min(colorT[1], 255.0f), std::min(colorT[2], 255.0f)};
}

Scene::Scene(RayTracer::Camera
camera, RayTracer::Object *object) : camera(std::move(camera)) {
    this->addObject(object);
}

Scene::Scene(RayTracer::Camera
camera, RayTracer::Object *object, RayTracer::Vec3
             background_color) : camera(std::move(camera)), background_color(background_color) {
    this->addObject(object);
}

Scene::Scene(RayTracer::Camera
camera) : camera(std::move(camera)) {}

void Scene::addObject(RayTracer::Object *object) {
    this->objects.push_back(object);
}

void Scene::removeLastObject() {
    this->objects.pop_back();
}

void Scene::removeObject(int index) {
    this->objects.erase(this->objects.begin() + index);
}

void Scene::clearObjects() {
    this->objects.clear();
}

void Scene::clearScene() {
    this->clearLightSources();
    this->clearObjects();
}

void Scene::addLightSource(RayTracer::Light *light_source) {
    this->light_sources.push_back(light_source);
}

void Scene::removeLightSource(int index) {
    this->light_sources.erase(this->light_sources.begin() + index);
}

void Scene::clearLightSources() {
    this->light_sources.clear();
}
