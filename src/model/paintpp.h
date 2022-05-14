//
// Created by carlo on 5/3/22.
//

#ifndef PAINT_PAINT_PP_H
#define PAINT_PAINT_PP_H
#include "iostream"
using namespace std;
#include "utils/doublyLinkedList.h"
#include "utils/vectorStructure.h"
#include "utils/utilities.h"
#include "image.h"

class PaintPP {

    int counterImage = 0;

    doublyLinkedList<string>* historyImage = nullptr;

    Image* currentImage = nullptr;

public:

    vectorStructure<Color> getCurrentImage();

    void createImage();

    virtual ~PaintPP();

    string getNextHistoryName();
};


#endif //PAINT_PAINT_PP_H
