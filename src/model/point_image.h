//
// Created by carlo on 5/16/22.
//

#ifndef PAINT_POINT_IMAGE_H
#define PAINT_POINT_IMAGE_H


struct PointImage{

    int x;

    int y;

    PointImage() : x(0), y(0) {};

    PointImage(int x, int y) : x(x), y(y) {};
};
struct vectorDireccion{
    bool Right;
    bool Up;
    bool Horizontal;
    bool Vertical;
    vectorDireccion():Right(false), Up(false) , Horizontal(false), Vertical(false){}
    vectorDireccion(bool Right, bool Up, bool Horizontal, bool Vertical):Right(Right), Up(Up),
                    Horizontal(Horizontal),Vertical(Vertical) {}
};

#endif //PAINT_POINT_IMAGE_H
