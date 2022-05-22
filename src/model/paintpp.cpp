//
// Created by carlo on 5/3/22.
//

#include <cstring>
#include "paintpp.h"
#include "utils/vectorStructure.h"

auto PaintPP::paintCoordinates(vectorStructure<PointImage> vectorMove, Image *imageCanvas,
                               int grossorE, Color colorPaint) -> Image * {
    int WIDTH = imageCanvas->getWidth();
    int HEIGHT = imageCanvas->getHeight();
//    Utilities::printMessageInfo(to_string(vectorMove.size()) + " y: " + to_string(vectorMove.size()));
    int mayorElementY = vectorMove.getElement(vectorMove.size()-1).y;
    int mayorElementX = vectorMove.getElement(vectorMove.size()-1).x;
    int menorElementY = vectorMove.getElement(0).y;
    int menorElementX = vectorMove.getElement(0).x;
    if ((vectorMove.getElement(0).y) > (vectorMove.getElement(vectorMove.size()-1).y)) {
        mayorElementY = vectorMove.getElement(0).y;
        menorElementY = vectorMove.getElement(vectorMove.size()-1).y;
    }
    if ((vectorMove.getElement(0).x) > (vectorMove.getElement(vectorMove.size()-1).x)) {
        mayorElementX = vectorMove.getElement(0).x;
        menorElementX = vectorMove.getElement(vectorMove.size()-1).x;
    }
    for(int index = 0; index < vectorMove.size(); index++){
        int elementY = vectorMove.getElement(index).y;
        int elementX = vectorMove.getElement(index).x;


        for(int applyGrossor = 0; applyGrossor < grossorE; applyGrossor++){
             if(elementX+applyGrossor < WIDTH && elementX+applyGrossor > 0
             && elementY+applyGrossor < HEIGHT && elementY+applyGrossor > 0
             &&(((elementY + applyGrossor < mayorElementY) && mayorElementX == menorElementX)
             || ((elementX + applyGrossor < mayorElementX) && mayorElementY == menorElementY))){
                 imageCanvas->setColor(colorPaint,
                                       (elementX),
                                       (elementY + applyGrossor));
                 imageCanvas->setColor(colorPaint,
                                       (elementX+ applyGrossor),
                                       (elementY));
             }
            if(elementX+applyGrossor < WIDTH && elementX+applyGrossor > 0
               && elementY+applyGrossor < HEIGHT && elementY+applyGrossor > 0
               && elementX-applyGrossor < WIDTH && elementX-applyGrossor > 0
               && elementY-applyGrossor < HEIGHT && elementY-applyGrossor > 0
               && mayorElementY != menorElementY
               && mayorElementX != menorElementX){
                imageCanvas->setColor(colorPaint,
                                      (elementX),
                                      (elementY + applyGrossor));
                imageCanvas->setColor(colorPaint,
                                      (elementX+ applyGrossor),
                                      (elementY));
                imageCanvas->setColor(colorPaint,
                                      (elementX),
                                      (elementY - applyGrossor));
                imageCanvas->setColor(colorPaint,
                                      (elementX- applyGrossor),
                                      (elementY));
            }
             if(elementX-applyGrossor < WIDTH && elementX-applyGrossor > 0
                && elementY-applyGrossor < HEIGHT && elementY-applyGrossor > 0
                && (((elementY - applyGrossor > menorElementY) && mayorElementX == menorElementX)
                || ((elementX - applyGrossor > menorElementX) && mayorElementY == menorElementY))){
                 imageCanvas->setColor(colorPaint,
                                       (elementX),
                                       (elementY - applyGrossor));
                 imageCanvas->setColor(colorPaint,
                                       (elementX - applyGrossor),
                                       (elementY));
             }
        }
    }
    return imageCanvas;
}

vectorStructure<PointImage> PaintPP::mouseMovement(int positionX, int positionY) {
    vectorStructure<PointImage> eraseMove;
    for(int startx = 1; startx < positionX; startx++)
        eraseMove.addElement(PointImage(startx,startx));
    return eraseMove;
}

auto PaintPP::erase(vectorStructure<PointImage> vectorMove, Image *imageCanvas, int grossorE)->Image* {
    Color colorErase = Color(255,255,255,255);
    imageCanvas = PaintPP::paintCoordinates(vectorMove,imageCanvas,grossorE, colorErase);
    return imageCanvas;
}

auto PaintPP::pencil(vectorStructure<PointImage> vectorMove, Image *imageCanvas, int grossorE,
                     Color colorSelect) -> Image * {
    imageCanvas = PaintPP::paintCoordinates(vectorMove,imageCanvas,grossorE,colorSelect);
    return imageCanvas;
}

auto PaintPP::pen(vectorStructure<PointImage> vectorTwoCordinates, Image *imageCanvas, int grossorE,
                  Color colorSelect) -> Image * {
    vectorDireccion lineDireccion(false,false,false,false);
    if((vectorTwoCordinates.getElement(1).x - vectorTwoCordinates.getElement(0).x) >= 0)
        lineDireccion.Right = true;
    if((vectorTwoCordinates.getElement(1).x - vectorTwoCordinates.getElement(0).x) == 0)
        lineDireccion.Vertical = true;
    if((vectorTwoCordinates.getElement(1).y - vectorTwoCordinates.getElement(0).y) >= 0)
        lineDireccion.Up = true;
    if((vectorTwoCordinates.getElement(1).y - vectorTwoCordinates.getElement(0).y) == 0)
        lineDireccion.Horizontal = true;


    int distance = (int)sqrt(pow((vectorTwoCordinates.getElement(0).x)-(vectorTwoCordinates.getElement(1).x),2)
            +pow((vectorTwoCordinates.getElement(0).y)-(vectorTwoCordinates.getElement(1).y),2));
    Utilities::printMessageInfo(to_string(distance) + "Distance");
    vectorStructure<PointImage> Move = PaintPP::rectLine(vectorTwoCordinates,distance,lineDireccion);
    imageCanvas = PaintPP::paintCoordinates(Move,imageCanvas,grossorE,colorSelect);
    return imageCanvas;
}

vectorStructure<PointImage> PaintPP::rectLine(vectorStructure<PointImage> coordinates, int distance,vectorDireccion lineDireccion) {
    vectorStructure<PointImage> allCoordinates;
    for(int allDistance = 0;allDistance < distance;allDistance++ ){
        if(lineDireccion.Up && !lineDireccion.Right){
            if(!lineDireccion.Horizontal && !lineDireccion.Vertical) {
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x + allDistance,
                                                         coordinates.getElement(1).y - allDistance));
            }
            else if(lineDireccion.Vertical){
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x,
                                                         coordinates.getElement(1).y - allDistance));
            }
            else{
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x + allDistance,
                                                         coordinates.getElement(1).y));
            }
        }
        else if(!lineDireccion.Up && lineDireccion.Right){
            if(!lineDireccion.Horizontal && !lineDireccion.Vertical) {
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x - allDistance,
                                                         coordinates.getElement(1).y + allDistance));
            }
            if(lineDireccion.Horizontal) {
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x - allDistance,
                                                         coordinates.getElement(1).y));
            }
            else{
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x,
                                                         coordinates.getElement(1).y + allDistance));
            }
        }
        else if(!lineDireccion.Up && !lineDireccion.Right){
            if(!lineDireccion.Horizontal && !lineDireccion.Vertical) {
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x + allDistance,
                                                         coordinates.getElement(1).y + allDistance));
            }
            else if(lineDireccion.Horizontal){
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x + allDistance,
                                                         coordinates.getElement(1).y));
            }
            else{
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x,
                                                         coordinates.getElement(1).y - allDistance));
            }
        }
        else{
            if(!lineDireccion.Horizontal && !lineDireccion.Vertical) {
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x - allDistance,
                                                         coordinates.getElement(1).y - allDistance));
            }
            else if(lineDireccion.Vertical){
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x,
                                                         coordinates.getElement(1).y - allDistance));
            }
            else{
                allCoordinates.addElement(PointImage(coordinates.getElement(1).x - allDistance,
                                                         coordinates.getElement(1).y));
            }
        }
    }
    return allCoordinates;
}

auto PaintPP::figureFourLines(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int side,int bottom) -> Image * {
    vectorStructure<PointImage> SquareVertices;
    vectorStructure<PointImage>Square;
    SquareVertices.addElement(PointImage(coord.x,coord.y));
    SquareVertices.addElement(PointImage(coord.x + bottom, coord.y));
    Square = PaintPP::rectLine(SquareVertices, bottom, vectorDireccion(true, false, true, false));
    imageCanvas = PaintPP::paintCoordinates(Square, imageCanvas,grossorE,colorSelect);
    SquareVertices.addElement(PointImage(coord.x, coord.y + side), 1);
    Square = PaintPP::rectLine(SquareVertices, side, vectorDireccion(true, true, false, true));
    imageCanvas = PaintPP::paintCoordinates(Square, imageCanvas,grossorE,colorSelect);
    SquareVertices.addElement(PointImage(coord.x + bottom, coord.y + side), 1);
    Square = PaintPP::rectLine(SquareVertices, side, vectorDireccion(true, true, false, true));
    imageCanvas = PaintPP::paintCoordinates(Square, imageCanvas,grossorE,colorSelect);
    SquareVertices.addElement(PointImage(coord.x + bottom, coord.y + side), 1);
    Square = PaintPP::rectLine(SquareVertices, bottom, vectorDireccion(true, false, true, false));
    imageCanvas = PaintPP::paintCoordinates(Square, imageCanvas,grossorE,colorSelect);
    return imageCanvas;
}

auto PaintPP::figureSquare(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int Size) -> Image * {
    imageCanvas = PaintPP::figureFourLines(coord,imageCanvas,grossorE,colorSelect,Size,Size);
    return imageCanvas;
}

auto PaintPP::figureRectangle(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int side,int bottom) -> Image * {
    imageCanvas = PaintPP::figureFourLines(coord,imageCanvas,grossorE,colorSelect,side,bottom);
    return imageCanvas;
}

auto PaintPP::figureTriangle(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect, int side) -> Image * {
    imageCanvas = PaintPP::figureThreeLines(coord, imageCanvas, grossorE, colorSelect, side);
    return imageCanvas;
}

auto PaintPP::figureThreeLines(PointImage coord, Image *imageCanvas, int grossorE, Color colorSelect,
                               int base) -> Image * {
    vectorStructure<PointImage> Vertices;
    vectorStructure<PointImage>Triangle;
    Vertices.addElement(PointImage(coord.x, coord.y));
    Vertices.addElement(PointImage(coord.x, coord.y));
    Triangle = PaintPP::rectLine(Vertices, base, vectorDireccion(true, false, true, false));
    imageCanvas = PaintPP::paintCoordinates(Triangle, imageCanvas, grossorE, colorSelect);
    Vertices.addElement(PointImage(coord.x - base/2, coord.y + base/2), 1);
    Triangle = PaintPP::rectLine(Vertices, base/2, vectorDireccion(false, true, false, false));
    imageCanvas = PaintPP::paintCoordinates(Triangle, imageCanvas, grossorE, colorSelect);
    Vertices.addElement(PointImage(coord.x - base/2, coord.y + base/2), 1);
    Triangle = PaintPP::rectLine(Vertices, base/2, vectorDireccion(true, true, false, false));
    imageCanvas = PaintPP::paintCoordinates(Triangle, imageCanvas, grossorE, colorSelect);
    return imageCanvas;
}

PaintPP::PaintPP(int width, int height) {
    historyImage.addElement(getNextHistoryName());
    createEmptyCanvas(width, height);
}

PaintPP::PaintPP(string pathImage) {
    historyImage.addElement(getNextHistoryName());
    createImageCanvas(pathImage);
}

void PaintPP::createEmptyCanvas(int width, int height){
    if(width<=1280 && height<= 720){
        currentImage = Image::createImageEmpty(width,height);
    }
    else{
        Utilities::printMessageError("The canvas is too big. "
                                     "The program is going to create the default size.");
        currentImage = Image::createImageEmpty(1280,720);
    }
    return;
}

void PaintPP::createImageCanvas(string path){
    ifstream file;
    file.open(path, ios::in | ios::binary);
    if(file.is_open()) {
        file.close();
        currentImage = Image::readImage(path);
    }
    else{
        Utilities::printMessageError("Exception opening/reading file. "
                                     "The program is going to create the default canvas.");
        createEmptyCanvas(1280, 720);
    }
    return;
}

vectorStructure<Color> PaintPP::getColorOfCurrentImage() {
    return currentImage->getColors();
}

string PaintPP::getNextHistoryName(){
    return string("canvas_") + to_string(++positionInHistory);
}

PaintPP::~PaintPP() {
    delete currentImage;
}

int PaintPP::getWidthCanvas(){
    return currentImage->getWidth();
}

int PaintPP::getHeightCanvas(){
    return currentImage->getHeight();
}

int PaintPP::getCounterImage() {
    return positionInHistory;
}

void PaintPP::saveImage(string path) {
//    auto path = historyImage->data;
    if(string("").compare(path)){
        path += ".bmp";
        currentImage->exportImage(path);
    }
    else{
        currentImage->exportImage("imageSaved.bmp");
    }
}

void PaintPP::drawImage(vectorStructure<PointImage> vectorMove, int thickness, Color color){
    checkEraseHistory();
    changeCurrentImage();
    pencil(vectorMove, currentImage, thickness, color);
}

void PaintPP::changeCurrentImage() {
    string name = historyImage.getElement(positionInHistory);
    cout << name << endl;
    saveImage(name);
    readyUndo = true;
    historyImage.addElement(getNextHistoryName());
}

bool PaintPP::getReadyUndo(){
    return readyUndo;
}

bool PaintPP::getReadyRedo() {
    return readyRedo;
}

void PaintPP::checkEraseHistory(){
    if(readyRedo){
        auto& tmp = historyImage;
        int final = tmp.size();
        for (int i = positionInHistory; i < final; ++i) {
            string command = "rm ";
            command += tmp.getElement(i) + ".bmp";
            char * cstr = new char [command.length()+1];
            strcpy(cstr, command.c_str());
            system(cstr);
            tmp.pop();
            delete[] cstr;
        }
        readyRedo = false;
    }
}

void PaintPP::vectorPrint(vectorStructure<PointImage>vectorMove){
    cout << "-----------Vector MOVE----------"<< endl;
    for (int i = 0; i < vectorMove.size(); ++i) {
        cout << "(" << vectorMove.getElement(i).x << "," << vectorMove.getElement(i).y << ")" << "\t";
    }
    cout << endl;
}

void PaintPP::eraseImage(vectorStructure<PointImage> vectorMove, int thickness) {
    checkEraseHistory();
    changeCurrentImage();
    erase(vectorMove, currentImage, thickness);
}

void PaintPP::createLineImage(vectorStructure<PointImage> vectorMove, int thickness, Color color) {
    checkEraseHistory();
    changeCurrentImage();
    pen(vectorMove, currentImage, thickness, color);
}

