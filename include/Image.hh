#pragma once
#include <vector>
#include "Vec3.hh"
#define MAX_PIXEL_VALUE 255

namespace IMAGE {
    class Image {
    public:
        Image(int const width,int const height);
        Image(const Image& img);
        Vec3 getPixel(int row, int col);
        void setPixel(int row, int col, int valueRed, int valueGreen,int valueBlue);
        bool save(const char* filepath);
    private:
        int width;
        int height;
        std::vector<std::vector<Vec3>> pixels;
    };
}