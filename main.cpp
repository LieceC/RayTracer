//#include <glfw/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/Vec3.hh"
#include "include/Image.hh"
#include "include/Sphere.hh"
#include "include/Camera.hh"
#include "include/Scene.hh"
//TODO add color class or color between 0 and 1 for more precision
int main()
{
    auto *v3 = new IMAGE::Vec3(3, 3, 3);
    //Creating material parameters for my sphere
    MaterialsParameters mc = {0.4,0.2,0.1,1.4,new IMAGE::Vec3(1,1,255)};
    auto sphere = new SCENE::Sphere(*v3,1,&mc);
    auto cam_pos = new IMAGE::Vec3(0, 0, 0);
    auto target = new IMAGE::Vec3(2, 2, 2);
    auto up = new IMAGE::Vec3(0, 1, 0);
    auto cam = new SCENE::Camera(1,1,1,cam_pos,target,up);
    auto *scene = new Scene(*cam,sphere,IMAGE::Vec3(54,82,94));
    auto light = new LIGHTING::Light({255,0,0},{0,4,2},{0,-1,0},0.7);
    auto light_2 = new LIGHTING::Light({0,255,0},{0,4,-2},{0,-1,0},0.7);
    scene->addLightSource(light);
    scene->addLightSource(light_2);
    scene->render(1080,1080,8); //Functional
}