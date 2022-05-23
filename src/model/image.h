//
// Created by carlo on 5/3/22.
//

#ifndef PAINT_IMAGE_H
#define PAINT_IMAGE_H
#include <iostream>
#include <fstream>
#include "iostream"
#include "utils/vectorStructure.h"
#include "utils/utilities.h"
using namespace std;

/**
 * the color of the image
 */
struct Color{

    /**
     * COlor red
     */
    float r;

    /**
     * color green
     */
    float g;

    /**
     * color blue
     */
    float b;

    /**
     * color alpha
     */
    float a;

    /**
     * create empty color
     */
    Color();

    /**
     * set color
     * @param a the alpha
     * @param r the red
     * @param g the green
     * @param b the blue
     */
    Color(float a, float r, float g, float b);
};

/**
 * the image in memory
 */
class Image {
private:

    /**
     * the width of image
     */
    const int width;

    /**
     * the height of image
     */
    const int height;

    /**
     * the default size header
     */
    static const int fileHeaderSize = 14;

    /**
     * the default size information
     */
    static const int informationHeaderSize = 40;

    /**
     * pad of image
     */
    const int paddingAmount;

    /**
     * size of image
     */
    const int fileSize;

    /**
     * the vector of all color of the image
     */
    vectorStructure<Color> colors;

    /**
     * set the color
     * @param color the color to set
     */
    [[maybe_unused]] void setColor(const Color& color);

public:

    /**
     * bite per pixel
     */
    static const int bitePerPixel = 4;

    /**
     * create the image
     * @param width the width
     * @param height the height
     */
    Image(int width, int height);

    /**
     * the delete function
     */
    ~Image();

    /**
     * get the color
     * @param x position x
     * @param y poistion y
     * @return the color
     */
    Color getColor(int x, int y);

    /**
     * set the color in position
     * @param color the color to set
     * @param i positon x
     * @param j position y
     */
    void setColor(const Color& color, int i, int j);

    /**
     * @brief Import the image. Doesn't working.
     * @param path The path of the image.
     */
    void exportImage(const string& path);

    /**
     * @brief Create an white image with size width x height.
     * @param widthN Width of the image.
     * @param heightN Height of the image.
     * @return The white image created.
     */
    static auto createImageEmpty(int widthN, int heightN) -> Image*;

    /**
     * the read image
     * @param path the path of image
     * @return return the new image
     */
    static auto readImage(const string& path) -> Image*;

    /**
     * the read image into old image
     * @param path the path of image
     * @param image the old image
     * @return return the new image
     */
    static auto readImage(const string &path, Image*& image)->Image*&;

    /**
     * get the width
     * @return the width
     */
    int getWidth();

    /**
     * get the height
     * @return the height
     */
    int getHeight();

    /**
     * the colors
     * @return the colors
     */
    vectorStructure<Color> getColors();

};

#endif //PAINT_IMAGE_H
