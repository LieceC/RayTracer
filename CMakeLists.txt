cmake_minimum_required(VERSION 3.17)
project(RayTracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracer main.cpp src/Vec3.cpp src/Image.cpp include/Image.hh include/Object.hh
        src/Ray.cpp include/Ray.hh src/Sphere.cpp include/Sphere.hh src/Camera.cpp include/Camera.hh
        src/Scene.cpp include/Scene.hh src/Light.cpp include/Light.hh
        include/MaterialsParameters.h src/utils.cpp include/utils.h)