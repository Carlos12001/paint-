//
// Created by carlo on 5/3/22.
//

#ifndef PAINT_IMAGE_H
#define PAINT_IMAGE_H
#include <iostream>
#include <fstream>
#include "iostream"
#include <glog/logging.h>
using namespace std;

struct Color{

    float r;

    float b;

    float g;

    Color();

    Color(float r, float b, float g);
};


class Image {
private:

    const int width;

    const int height;

    static const int fileHeaderSize = 14;

    static const int informationHeaderSize = 40;

    const int paddingAmount;

    const int fileSize;

    vector<Color> colors;

public:

    Image(int width, int height);

    ~Image();

    Color getColor(int x, int y);

    void setColor(const Color& color, int x, int y);

    /**
     * @brief Import the image. Doesn't working.
     * @param path The path of the image.
     */
    void exportImage(const string& path);

    /**
     * @brief Create an white image with size widthxheight.
     * @param widthN Width of the image.
     * @param heightN Height of the image.
     * @return The white image created.
     */
    static auto createImageEmpty(int widthN, int heightN)-> Image *;

    const int getWidth();

    const int getHeight();

    vector<Color> &getColors();

    void setColors(vector<Color> &colors);
};

#endif //PAINT_IMAGE_H
