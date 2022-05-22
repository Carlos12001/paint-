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
#include <cstdlib>
#include "utils/vectorMovement.h"
#include "point_image.h"


class PaintPP {
    private:

    static auto paintCoordinates(vectorStructure<PointImage> vectorMove, Image* imageCanvas, int grossorE, Color colorPaint)->Image*; //paint-funcion-auxiliar-erase-line-draw-figure

    static vectorStructure<PointImage> rectLine(vectorStructure<PointImage> coordinates,int distance,vectorDireccion lineDireccion);

    static auto figureFourLines(PointImage coord, Image* imageCanvas, int grossorE,Color colorSelect,int Side, int Bottom)->Image*;

    static auto figureThreeLines(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect,
                                 int base) -> Image *;

    static vectorStructure<PointImage> mouseMovement(int positionX, int positionY);

    static auto erase(vectorStructure<PointImage> vectorMove, Image* imageCanvas,int grossorE)->Image*; //erease

    static auto pencil(vectorStructure<PointImage> vectorMove, Image* imageCanvas,int grossorE, Color colorSelect)->Image*; //draw

    static auto pen(vectorStructure<PointImage> vectorTwoCordinates, Image* imageCanvas, int grossorE, Color colorSelect)->Image*; //line

    static auto figureSquare(PointImage coord, Image* imageCanvas, int grossorE,Color colorSelect,int Size)->Image*;

    static auto figureRectangle(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int side, int bottom)-> Image*;

    static auto figureTriangle(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int side)-> Image*;

    int positionInHistory = -1;

    bool readyUndo = false;

    bool readyRedo = false;

    vectorStructure<string> historyImage;

    Image* currentImage = nullptr;

    void createEmptyCanvas(int width, int height);

    string getNextHistoryName();

    void createImageCanvas(string path);

    void changeCurrentImage();

    void checkEraseHistory();

public:

    PaintPP(int width, int height);

    PaintPP(string pathImage);

    vectorStructure<Color> getColorOfCurrentImage();

    int getWidthCanvas();

    int getHeightCanvas();

    int getCounterImage();

    virtual ~PaintPP();

    void drawImage(vectorStructure<PointImage> vectorMove, int thickness, Color color);

    void eraseImage(vectorStructure<PointImage> vectorMove, int thickness);

    void createLineImage(vectorStructure<PointImage> vectorMove, int thickness, Color color);

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

    bool getReadyUndo();

    bool getReadyRedo();

    void vectorPrint(vectorStructure<PointImage> vectorMove);

    void removeHistory();
};


#endif //PAINT_PAINT_PP_H
