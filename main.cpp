#include "include/Vec3.hh"
#include "include/Image.hh"
#include "include/Sphere.hh"
#include "include/Camera.hh"
#include "include/Scene.hh"
//TODO add color class or color between 0 and 1 for more precision
int main()
{
    IMAGE::Vec3 v3(3, 3, 3);
    //Creating material parameters for my sphere
    MaterialsParameters mc = {0.4,0.5,0.2,5};
    SCENE::Sphere sphere(v3,1,IMAGE::Vec3(255,255,255),mc);
    IMAGE::Vec3 cam_pos(0, 0, 0);
    IMAGE::Vec3 target(3, 3, 3);
    IMAGE::Vec3 up(0, 1, 0);
    SCENE::Camera cam(1,1,1,cam_pos,target,up);
    Scene scene(cam,&sphere,IMAGE::Vec3(54,82,94));
    LIGHTING::Light light({255,255,255},{0,4,2},0.2);
    //LIGHTING::Light light_2({0,255,0},{0,4,-2},0.2);
    scene.addLightSource(&light);
    //scene.addLightSource(&light_2);
    scene.render(1000,1000,8); //Functional
}