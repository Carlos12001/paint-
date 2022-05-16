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
#include "point_image.h"


class PaintPP {
    private:

    static auto paintCoordinates(vectorStructure<PointImage> vectorMove, Image* imageCanvas, int grossorE, Color colorPaint)->Image*;
    static vectorStructure<PointImage> rectLine(vectorStructure<PointImage> coordinates,int distance,vectorDireccion lineDireccion);
    static auto figureFourLines(PointImage coord, Image* imageCanvas, int grossorE,Color colorSelect,int Side, int Bottom)->Image*;
    static auto figureThreeLines(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect,
                                 int base) -> Image *;

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

    static vectorStructure<PointImage> mouseMovement(int positionX, int positionY);

    static auto erase(vectorStructure<PointImage> vectorMove, Image* imageCanvas,int grossorE)->Image*;

    static auto pencil(vectorStructure<PointImage> vectorMove, Image* imageCanvas,int grossorE, Color colorSelect)->Image*;

    static auto pen(vectorStructure<PointImage> vectorTwoCordinates, Image* imageCanvas, int grossorE, Color colorSelect)->Image*;

    static auto figureSquare(PointImage coord, Image* imageCanvas, int grossorE,Color colorSelect,int Size)->Image*;

    static auto figureRectangle(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int side, int bottom)-> Image*;

    static auto figureTriangle(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int side)-> Image*;
};


#endif //PAINT_PAINT_PP_H
