//
// Created by carlo on 5/3/22.
//

#include "image.h"

Color::Color():r(0), b(0), g(0){}

Color::Color(float r, float b, float g):r(r), b(b), g(g) {}

Image::Image(unsigned int width, unsigned int height):width(width), height(height){
}

Image::~Image() {

}

Color Image::getColor(unsigned int x, unsigned int y) {
    return colors[y * width + x];
}

void Image::setColor(const Color &color, unsigned int x, unsigned int y){
    (colors[y*height + x]).r = color.r;
    (colors[y*height + x]).g = color.g;
    (colors[y*height + x]).b = color.b;
    return;
}

void Image::exportImage(const string path) {
    ofstream file;
    file.open(path, ios::out | ios::binary);

    if(!file.is_open()){

    }
    return;
}
