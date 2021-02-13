
#include "../include/Image.hh"
#include <vector>
#include <fstream>

IMAGE::Image::Image(int width,int height) {
    this->height = height;
    this->width = width;
    this->pixels.resize(height, std::vector<Vec3>(width));
}

IMAGE::Image::Image(const IMAGE::Image &img) {
    this->height = img.height;
    this->width = img.width;
    this->pixels = img.pixels;
}

IMAGE::Vec3 IMAGE::Image::getPixel(int row, int col) {
    return this->pixels[row][col];
}
// To-DO : Error handling
bool IMAGE::Image::save(const char *filepath) {
    std::ofstream file(filepath);
    file << "P3" << std::endl;
    file << this->width << " " << this->height<<std::endl;
    file << MAX_PIXEL_VALUE << std::endl;

    std::vector<std::vector<IMAGE::Vec3>>::iterator row;
    std::vector<IMAGE::Vec3>::iterator col;
    for (row = this->pixels.begin(); row != this->pixels.end(); ++row) {
        for(col = row->begin(); col != row->end(); ++col){
            file << (*col) << " ";
        }
        file << std::endl;
    }
    file.close();
    return true;

}

void IMAGE::Image:: setPixel(int row, int col, int valueRed, int valueGreen,int valueBlue) {
    this->pixels[row][col] = new IMAGE::Vec3(valueRed,valueGreen,valueBlue);
}
