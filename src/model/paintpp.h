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
using namespace std;

class PaintPP {
    public:

    static auto erase(vectorStructure<int> VectorX, vectorStructure<int> VectorY, Image* imageCanvas, int grossorE)->Image*;
    static vectorStructure<int> mouseMovement(int position);
};


#endif //PAINT_PAINT_PP_H
