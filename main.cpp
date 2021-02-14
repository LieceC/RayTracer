#include "include/Vec3.hh"
#include "include/Sphere.hh"
#include "include/Camera.hh"
#include "include/Scene.hh"

//TODO add color class or color between 0 and 1 for more precision
int main() {
    //Creating material parameters for my sphere
    MaterialsParameters mc = {0.4, 0.5, 0.2, 100};
    RayTracer::Sphere sphere(RayTracer::Vec3(3, 3, 3), 1, RayTracer::Vec3(255, 255, 255), mc);
    RayTracer::Sphere sphere2(RayTracer::Vec3(0, 3, 3), 1, RayTracer::Vec3(255, 255, 255), mc);

    RayTracer::Vec3 cam_pos(-3, -3, -3);
    RayTracer::Vec3 target(3, 3, 3);
    RayTracer::Vec3 up(0, 1, 0);
    RayTracer::Camera cam(1, 1, 1, cam_pos, target, up);
    Scene scene(cam, &sphere, RayTracer::Vec3(54, 82, 94));
    scene.addObject(&sphere2);
    //scene.addObject(&sphere3);
    //scene.addObject(&sphere4);
    //scene.addObject(&sphere5);
    RayTracer::Light light({255, 0, 255}, {4, 0, 0}, 0.2);
    RayTracer::Light light_2({255, 255, 255}, {0, 4, 0}, 0.2);
    scene.addLightSource(&light);
    scene.addLightSource(&light_2);
    scene.render(1500, 1500, 8); //Functional
}