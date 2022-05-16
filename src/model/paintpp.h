//
// Created by carlo on 5/3/22.
//

#ifndef PAINT_PAINT_PP_H
#define PAINT_PAINT_PP_H

#include <iostream>
#include <fstream>
#include "iostream"
#include "image.h"
#include "utils/vectorStructure.h"
#include "utils/utilities.h"
#include "utils/vectorMovement.h"
#include <math.h>
using namespace std;

class PaintPP {
    private:

    static auto paintCoordinates(vectorStructure<vectorMovement> vectorMove, Image* imageCanvas, int grossorE, Color colorPaint)->Image*;
    static vectorStructure<vectorMovement> rectLine(vectorStructure<vectorMovement> coordinates,int distance,vectorDireccion lineDireccion);

    public:

    static vectorStructure<vectorMovement> mouseMovement(int positionX, int positionY);
    static auto erase(vectorStructure<vectorMovement> vectorMove, Image* imageCanvas,int grossorE)->Image*;
    static auto pencil(vectorStructure<vectorMovement> vectorMove, Image* imageCanvas,int grossorE, Color colorSelect)->Image*;
    static auto pen(vectorStructure<vectorMovement> vectorTwoCordinates, Image* imageCanvas, int grossorE, Color colorSelect)->Image*;
    static auto figureSquare(vectorMovement coord, Image* imageCanvas, int grossorE,Color colorSelect,int Size)->Image*;
};

#endif //PAINT_PAINT_PP_H
