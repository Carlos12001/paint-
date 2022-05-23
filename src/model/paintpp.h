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
#include "point_image.h"


class PaintPP {
    private:

    enum FiltersImage{
        White,
        Blue,
        Green,
        Red
    };

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

    void changedColor(Image *imageCanvas, FiltersImage setFilter);

    Color filterWhite();

    Color filterBlue(Color colorTemp);

    Color filterGreen(Color colorTemp);

    Color filterRed(Color colorTemp);

public:

    PaintPP(int width, int height);

    PaintPP(string pathImage);

    vectorStructure<Color> getColorOfCurrentImage();

    int getWidthCanvas();

    int getHeightCanvas();

    virtual ~PaintPP();

    void drawImage(vectorStructure<PointImage> vectorMove, int thickness, Color color);

    void eraseImage(vectorStructure<PointImage> vectorMove, int thickness);

    void createLineImage(vectorStructure<PointImage> vectorMove, int thickness, Color color);

    void magicSelectImage(PointImage pointClick);

    void createSquareImage(PointImage pointCickled,int tickness, Color color,int size);

    void createTriangleImage(PointImage pointCickled,int tickness, Color color,int size);

    void createRectangleImage(PointImage pointCickled,int tickness, Color color,int size, int size2);

    Color getPicker(PointImage pointCickled);

    void paintFill(PointImage click, Color color);

    void saveImage(string pathImage);

    void redoImage();

    void undoImage();

    void doFilterRImage();

    void doFilterGImage();

    void doFilterBImage();

    void rotateImage();

    void clearAllCanvasImage();

    bool getReadyUndo();

    bool getReadyRedo();

    [[maybe_unused]] void vectorPrint(vectorStructure<PointImage> vectorMove);

    void removeHistory();

    string stringCheckCanvas(string text);
};


#endif //PAINT_PAINT_PP_H
