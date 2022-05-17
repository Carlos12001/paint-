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

struct Color{

    float r;

    float g;

    float b;

    float a;

    Color();


    Color(float a, float r, float g, float b);
};


class Image {
private:

    const int width;

    const int height;

    static const int fileHeaderSize = 14;

    static const int informationHeaderSize = 40;

    const int paddingAmount;

    const int fileSize;

    vectorStructure<Color> colors;

    void setColor(const Color& color);

public:

    static const int bitePerPixel = 4;

    Image(int width, int height);

    ~Image();

    Color getColor(int x, int y);

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

    static auto readImage(const string& path) -> Image*;

    int getWidth();

    int getHeight();

    vectorStructure<Color> getColors();

};

#endif //PAINT_IMAGE_H
