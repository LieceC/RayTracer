#include "include/Vec3.hh"
#include "include/Image.hh"
#include "include/Sphere.hh"
#include "include/Camera.hh"
#include "include/Scene.hh"

//TODO add color class or color between 0 and 1 for more precision
int main() {
    //Creating material parameters for my sphere
    MaterialsParameters mc = {0.4, 0.5, 0.2, 100};
    SCENE::Sphere sphere(IMAGE::Vec3(3, 3, 3), 1, IMAGE::Vec3(255, 255, 255), mc);
    SCENE::Sphere sphere2(IMAGE::Vec3(0, 3, 3), 1, IMAGE::Vec3(255, 255, 255), mc);

    IMAGE::Vec3 cam_pos(-3, -3, -3);
    IMAGE::Vec3 target(3, 3, 3);
    IMAGE::Vec3 up(0, 1, 0);
    SCENE::Camera cam(1, 1, 1, cam_pos, target, up);
    Scene scene(cam, &sphere, IMAGE::Vec3(54, 82, 94));
    scene.addObject(&sphere2);
    //scene.addObject(&sphere3);
    //scene.addObject(&sphere4);
    //scene.addObject(&sphere5);
    LIGHTING::Light light({255, 0, 255}, {4, 0, 0}, 0.2);
    LIGHTING::Light light_2({255, 255, 255}, {0, 4, 0}, 0.2);
    scene.addLightSource(&light);
    scene.addLightSource(&light_2);
    scene.render(1500, 1500, 8); //Functional
}