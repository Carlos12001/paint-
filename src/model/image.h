//
// Created by carlo on 5/3/22.
//

#ifndef PAINT_IMAGE_H
#define PAINT_IMAGE_H
#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <glob.h>


struct Color{

    float r;

    float b;

    float g;

    Color();

    Color(float r, float b, float g);
};


class Image {
private:

    unsigned int width;

    unsigned int height;

    vector<Color> colors;

public:

    Image(unsigned int width, unsigned int height);

    ~Image();

    Color getColor(unsigned int x, unsigned int y);

    void setColor(const Color& color, unsigned int x, unsigned int y);

    void exportImage(const string path);

};

#endif //PAINT_IMAGE_H
