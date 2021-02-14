#pragma once
#include <vector>
#include "Vec3.hh"
#define MAX_PIXEL_VALUE 255

namespace RayTracer {
    /**
     * An image is described by its resolution [width*height] and its value on each [pixels]
     */
    class Image {
    public:
        /**
         * Create an image full of black pixels of width [width] and height [height]
         * @param width
         * @param height
         */
        Image(int const width,int const height);
        /**
         * Copy constructor of Image
         * @param img The image we want to copy
         */
        Image(const Image& img);
        /**
         * Return the RGB value at row [row] and column [column] in the Image
         * @param row The row of the pixel we want to get
         * @param col The column of the pixel we want to get
         * @return Vec3 (R,G,B) of this pixel
         */
        Vec3 getPixel(int row, int col);
        /**
         * Set the RGB value of the pixel at position [row,col] to the value [valueRed,valueGreen,valueBlue]
         * @param row Row position of the pixel
         * @param col Column position of the pixel
         * @param valueRed The red shade of the pixel
         * @param valueGreen The green shade of the pixel
         * @param valueBlue The blue shade of the pixel
         */
        void setPixel(int row, int col, const RayTracer::Vec3& color);
        /**
         * Save the image in the basic plain ppm format in the folder filepath relative to where
         * the executable is found. You can pass an absolute path.
         * @param filepath
         * @return True if the save has been successful, False otherwise
         */
        bool save(const char* filepath); //TODO error handling
    private:
        int width;
        int height;
        std::vector<std::vector<Vec3>> pixels;
    };
}