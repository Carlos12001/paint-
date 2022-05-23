//
// Created by carlo on 5/16/22.
//

#ifndef PAINT_POINT_IMAGE_H
#define PAINT_POINT_IMAGE_H

/**
 * The position in image
 */
struct PointImage{

    /**
     * Position x
     */
    int x;

    /**
     * position y
     */
    int y;

    /**
     * the constructor set 0,0
     */
    PointImage() : x(0), y(0) {};

    /**
     * the constor for inital x, y
     * @param x position x
     * @param y positon y
     */
    PointImage(int x, int y) : x(x), y(y) {};
};

/**
 * THe direction of vector
 */
struct vectorDireccion{

    /**
     * see right
     */
    bool Right;

    /**
     * see up
     */
    bool Up;

    /**
     * see horixontal
     */
    bool Horizontal;

    /**
     * see vertical
     */
    bool Vertical;

    /**
     * the default constructor
     */
    vectorDireccion():Right(false), Up(false) , Horizontal(false), Vertical(false){}

    /**
     * the constructor of inital values
     * @param Right the right
     * @param Up the up
     * @param Horizontal tje horizotal
     * @param Vertical the vertical
     */
    vectorDireccion(bool Right, bool Up, bool Horizontal, bool Vertical):Right(Right), Up(Up),
                    Horizontal(Horizontal),Vertical(Vertical) {}
};

#endif //PAINT_POINT_IMAGE_H
