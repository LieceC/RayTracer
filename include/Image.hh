#pragma once
#include <vector>
#include "Vec3.hh"
#define MAX_PIXEL_VALUE 255

namespace IMAGE {
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
         * @param img
         */
        Image(const Image& img);
        /**
         * Return the RGB value at row [row] and column [column] in the Image
         * @param row
         * @param col
         * @return Vec3 (R,G,B)
         */
        Vec3 getPixel(int row, int col);
        /**
         * set the RGB value of the pixel at position [row,col] to the value [valueRed,valueGreen,valueBlue]
         * @param row
         * @param col
         * @param valueRed
         * @param valueGreen
         * @param valueBlue
         */
        void setPixel(int row, int col, int valueRed, int valueGreen,int valueBlue);
        /**
         * Save the image in the basic plain ppm format in the folder filepath relative to where
         * the executable is found. You can pass an absolute path.
         * @param filepath
         * @return True if the save has been successful, False otherwise
         */
        bool save(const char* filepath); //TODO eror handling
    private:
        int width;
        int height;
        std::vector<std::vector<Vec3>> pixels;
    };
}