
#include "../include/Image.hh"
#include <vector>
#include <fstream>

RayTracer::Image::Image(int width, int height) : height(height), width(width) {
    this->pixels.resize(height, std::vector<Vec3>(width));
}

RayTracer::Image::Image(const RayTracer::Image &img) : height(img.height), width(img.width), pixels(img.pixels) {
    this->height = img.height;
    this->width = img.width;
    this->pixels = img.pixels;
}

RayTracer::Vec3 RayTracer::Image::getPixel(int row, int col) {
    return this->pixels[row][col];
}

// TODO : Error handling
bool RayTracer::Image::save(const char *filepath) {
    std::ofstream file(filepath);
    file << "P3" << std::endl << this->width << " " << this->height << std::endl << MAX_PIXEL_VALUE << std::endl;

    std::vector<std::vector<RayTracer::Vec3>>::iterator row;
    std::vector<RayTracer::Vec3>::iterator col;

    for (row = this->pixels.begin(); row != this->pixels.end(); ++row) {
        for (col = row->begin(); col != row->end(); ++col) {
            file << (*col) << " ";
        }
        file << std::endl;
    }
    file.close();
    return true;

}

void RayTracer::Image::setPixel(int row, int col, const RayTracer::Vec3 &color) {
    this->pixels[row][col] = color;
}
