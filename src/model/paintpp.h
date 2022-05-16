//
// Created by carlo on 5/3/22.
//

#ifndef PAINT_PAINT_PP_H
#define PAINT_PAINT_PP_H
#include <iostream>
using namespace std;
#include "utils/doublyLinkedList.h"
#include "utils/vectorStructure.h"
#include "utils/utilities.h"
#include "image.h"
#include <fstream>
#include <math.h>
#include "utils/vectorMovement.h"


class PaintPP {
    private:

    static auto paintCoordinates(vectorStructure<vectorMovement> vectorMove, Image* imageCanvas, int grossorE, Color colorPaint)->Image*;
    static vectorStructure<vectorMovement> rectLine(vectorStructure<vectorMovement> coordinates,int distance,vectorDireccion lineDireccion);

    int counterImage = 0;

    doublyLinkedList<string>* historyImage = nullptr;

    Image* currentImage = nullptr;

    void createEmptyCanvas(int width, int height);

    string getNextHistoryName();

    void createImageCanvas(string path);

public:

    PaintPP(int width, int height);

    PaintPP(string pathImage);

    vectorStructure<Color> getColorOfCurrentImage();

    int getWidthCanvas();

    int getHeightCanvas();

    virtual ~PaintPP();

    void saveImage();

    public:

    static vectorStructure<vectorMovement> mouseMovement(int positionX, int positionY);

    static auto erase(vectorStructure<vectorMovement> vectorMove, Image* imageCanvas,int grossorE)->Image*;

    static auto pencil(vectorStructure<vectorMovement> vectorMove, Image* imageCanvas,int grossorE, Color colorSelect)->Image*;

    static auto pen(vectorStructure<vectorMovement> vectorTwoCordinates, Image* imageCanvas, int grossorE, Color colorSelect)->Image*;

    static auto figureSquare(vectorMovement coord, Image* imageCanvas, int grossorE,Color colorSelect,int Size)->Image*;
};


#endif //PAINT_PAINT_PP_H
