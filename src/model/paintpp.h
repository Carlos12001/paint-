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
#include "point_image.h"


class PaintPP {
    private:

    int counterImage = 0;

    doublyLinkedList<string>* historyImage = nullptr;

    Image* currentImage = nullptr;

    static auto paintCoordinates(vectorStructure<vectorMovement> vectorMove, Image* imageCanvas, int grossorE, Color colorPaint)->Image*;
    static vectorStructure<vectorMovement> rectLine(vectorStructure<vectorMovement> coordinates,int distance,vectorDireccion lineDireccion);

    static auto erase(vectorStructure<vectorMovement> vectorMove, Image* imageCanvas,int grossorE)->Image*;

    static auto pencil(vectorStructure<vectorMovement> vectorMove, Image* imageCanvas,int grossorE, Color colorSelect)->Image*;

    static auto pen(vectorStructure<vectorMovement> vectorTwoCordinates, Image* imageCanvas, int grossorE, Color colorSelect)->Image*;

    static auto figureSquare(vectorMovement coord, Image* imageCanvas, int grossorE,Color colorSelect,int Size)->Image*;

    void createEmptyCanvas(int width, int height);

    string getNextHistoryName();

    void createImageCanvas(string path);

public:

    PaintPP(int width, int height);

    PaintPP(string pathImage);

    vectorStructure<Color> getColorOfCurrentImage();

    int getWidthCanvas();

    int getHeightCanvas();

    int getCounterImage();

    virtual ~PaintPP();

    [[maybe_unused]] static vectorStructure<vectorMovement> mouseMovementEmulation(int positionX, int positionY);

    void updateCurrentImage(Image* theNewImage);

    void drawImage(vectorStructure<PointImage> vectorMove, int thickness, Color color);

    void eraseImage(vectorStructure<PointImage> vectorMove, int thickness);

    void createLineImage(PointImage* arrayPoints, int thickness);

    void magicSelectImage(PointImage pointCickled);

    void chopSquareImage(PointImage* arrayPoints);

    void chopFreeImage(vectorStructure<PointImage> vectorMove);

    void createSquareImage(PointImage pointCickled);

    void createTriangleImage(PointImage pointCickled);

    void createRectangleImage(PointImage pointCickled);

    Color getPicker(PointImage pointCickled);

    void paintFill(vectorStructure<PointImage> vectorMove, Color color);

    void saveImage(string pathImage);

    void redoImage();

    void undoImage();

    void openImage(string pathImage);

    void doFilterRImage();

    void doFilterGImage();

    void doFilterBImage();

    void rotateImage();

};


#endif //PAINT_PAINT_PP_H
