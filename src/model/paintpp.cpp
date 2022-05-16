//
// Created by carlo on 5/3/22.
//

#include "paintpp.h"
#include "utils/vectorStructure.h"

auto PaintPP::paintCoordinates(vectorStructure<vectorMovement> vectorMove, Image *imageCanvas,
                               int grossorE, Color colorPaint) -> Image * {
    int WIDTH = imageCanvas->getWidth();
    int HEIGHT = imageCanvas->getHeight();
    Utilities::printMessageInfo(to_string(vectorMove.size()) + " y: " + to_string(vectorMove.size()));
    int mayorElementY = vectorMove.getElement(vectorMove.size()-1).PosY;
    int mayorElementX = vectorMove.getElement(vectorMove.size()-1).PosX;
    int menorElementY = vectorMove.getElement(0).PosY;
    int menorElementX = vectorMove.getElement(0).PosX;
    if ((vectorMove.getElement(0).PosY) > (vectorMove.getElement(vectorMove.size()-1).PosY)) {
        mayorElementY = vectorMove.getElement(0).PosY;
        menorElementY = vectorMove.getElement(vectorMove.size()-1).PosY;
    }
    if ((vectorMove.getElement(0).PosX) > (vectorMove.getElement(vectorMove.size()-1).PosX)) {
        mayorElementX = vectorMove.getElement(0).PosX;
        menorElementX = vectorMove.getElement(vectorMove.size()-1).PosX;
    }
    for(int index = 0; index < vectorMove.size(); index++){
        int elementY = vectorMove.getElement(index).PosY;
        int elementX = vectorMove.getElement(index).PosX;


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
               && mayorElementY != menorElementY
               && mayorElementX != menorElementX){
                imageCanvas->setColor(colorPaint,
                                      (elementX),
                                      (elementY + applyGrossor));
                imageCanvas->setColor(colorPaint,
                                      (elementX+ applyGrossor),
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

vectorStructure<vectorMovement> PaintPP::mouseMovement(int positionX, int positionY) {
    vectorStructure<vectorMovement> eraseMove;
    for(int startPosX = 1; startPosX < positionX; startPosX++)
        eraseMove.addElement(vectorMovement(startPosX,startPosX));
    return eraseMove;
}

auto PaintPP::erase(vectorStructure<vectorMovement> vectorMove, Image *imageCanvas, int grossorE)->Image* {
    Color colorErase = Color(255,255,255,255);
    imageCanvas = PaintPP::paintCoordinates(vectorMove,imageCanvas,grossorE, colorErase);
    return imageCanvas;
}

auto PaintPP::pencil(vectorStructure<vectorMovement> vectorMove, Image *imageCanvas, int grossorE,
                     Color colorSelect) -> Image * {
    imageCanvas = PaintPP::paintCoordinates(vectorMove,imageCanvas,grossorE,colorSelect);
    return imageCanvas;
}

auto PaintPP::pen(vectorStructure<vectorMovement> vectorTwoCordinates, Image *imageCanvas, int grossorE,
                  Color colorSelect) -> Image * {
    vectorDireccion lineDireccion(false,false,false,false);
    if((vectorTwoCordinates.getElement(1).PosX - vectorTwoCordinates.getElement(0).PosX) >= 0)
        lineDireccion.Right = true;
    if((vectorTwoCordinates.getElement(1).PosX - vectorTwoCordinates.getElement(0).PosX) == 0)
        lineDireccion.Vertical = true;
    if((vectorTwoCordinates.getElement(1).PosY - vectorTwoCordinates.getElement(0).PosY) >= 0)
        lineDireccion.Up = true;
    if((vectorTwoCordinates.getElement(1).PosY - vectorTwoCordinates.getElement(0).PosY) == 0)
        lineDireccion.Horizontal = true;


    int distance = (int)sqrt(pow((vectorTwoCordinates.getElement(0).PosX)-(vectorTwoCordinates.getElement(1).PosX),2)
            +pow((vectorTwoCordinates.getElement(0).PosY)-(vectorTwoCordinates.getElement(1).PosY),2));
    Utilities::printMessageInfo(to_string(distance) + "Distance");
    vectorStructure<vectorMovement> Move = PaintPP::rectLine(vectorTwoCordinates,distance,lineDireccion);
    imageCanvas = PaintPP::paintCoordinates(Move,imageCanvas,grossorE,colorSelect);
    return imageCanvas;
}

vectorStructure<vectorMovement> PaintPP::rectLine(vectorStructure<vectorMovement> coordinates, int distance,vectorDireccion lineDireccion) {
    vectorStructure<vectorMovement> allCoordinates;
    for(int allDistance = 0;allDistance < distance;allDistance++ ){
        if(lineDireccion.Up && !lineDireccion.Right){
            if(!lineDireccion.Horizontal && !lineDireccion.Vertical) {
                allCoordinates.addElement(vectorMovement(coordinates.getElement(1).PosX + allDistance,
                                                         coordinates.getElement(1).PosY - allDistance));
            }
            else if(lineDireccion.Vertical){
                allCoordinates.addElement(vectorMovement(coordinates.getElement(1).PosX,
                                                         coordinates.getElement(1).PosY - allDistance));
            }
            else{
                allCoordinates.addElement(vectorMovement(coordinates.getElement(1).PosX + allDistance,
                                                         coordinates.getElement(1).PosY));
            }
        }
        else if(!lineDireccion.Up && lineDireccion.Right){
            if(!lineDireccion.Horizontal && !lineDireccion.Vertical) {
                allCoordinates.addElement(vectorMovement(coordinates.getElement(1).PosX - allDistance,
                                                         coordinates.getElement(1).PosY + allDistance));
            }
            if(lineDireccion.Horizontal) {
                allCoordinates.addElement(vectorMovement(coordinates.getElement(1).PosX - allDistance,
                                                         coordinates.getElement(1).PosY));
            }
            else{
                allCoordinates.addElement(vectorMovement(coordinates.getElement(1).PosX,
                                                         coordinates.getElement(1).PosY + allDistance));
            }
        }
        else if(!lineDireccion.Up && !lineDireccion.Right){
            if(!lineDireccion.Horizontal && !lineDireccion.Vertical) {
                allCoordinates.addElement(vectorMovement(coordinates.getElement(1).PosX + allDistance,
                                                         coordinates.getElement(1).PosY + allDistance));
            }
            else if(lineDireccion.Horizontal){
                allCoordinates.addElement(vectorMovement(coordinates.getElement(1).PosX + allDistance,
                                                         coordinates.getElement(1).PosY));
            }
            else{
                allCoordinates.addElement(vectorMovement(coordinates.getElement(1).PosX,
                                                         coordinates.getElement(1).PosY - allDistance));
            }
        }
        else{
            if(!lineDireccion.Horizontal && !lineDireccion.Vertical) {
                allCoordinates.addElement(vectorMovement(coordinates.getElement(1).PosX - allDistance,
                                                         coordinates.getElement(1).PosY - allDistance));
            }
            else if(lineDireccion.Vertical){
                allCoordinates.addElement(vectorMovement(coordinates.getElement(1).PosX,
                                                         coordinates.getElement(1).PosY - allDistance));
            }
            else{
                allCoordinates.addElement(vectorMovement(coordinates.getElement(1).PosX - allDistance,
                                                         coordinates.getElement(1).PosY));
            }
        }
    }
    return allCoordinates;
}

auto PaintPP::figureSquare(vectorMovement coord, Image *imageCanvas, int grossorE, Color colorSelect, int Size) -> Image * {
    vectorStructure<vectorMovement> SquareVertices;
    vectorStructure<vectorMovement>Square;
    SquareVertices.addElement(vectorMovement(coord.PosX,coord.PosY));
    SquareVertices.addElement(vectorMovement(coord.PosX + Size, coord.PosY));
    Square = PaintPP::rectLine(SquareVertices, Size, vectorDireccion(true, false, true, false));
    imageCanvas = PaintPP::paintCoordinates(Square, imageCanvas,grossorE,colorSelect);
    SquareVertices.addElement(vectorMovement(coord.PosX, coord.PosY + Size), 1);
    Square = PaintPP::rectLine(SquareVertices, Size, vectorDireccion(true, true, false, true));
    imageCanvas = PaintPP::paintCoordinates(Square, imageCanvas,grossorE,colorSelect);
    SquareVertices.addElement(vectorMovement(coord.PosX + Size, coord.PosY + Size), 1);
    Square = PaintPP::rectLine(SquareVertices, Size, vectorDireccion(true, true, false, true));
    imageCanvas = PaintPP::paintCoordinates(Square, imageCanvas,grossorE,colorSelect);
    SquareVertices.addElement(vectorMovement(coord.PosX + Size, coord.PosY + Size), 1);
    Square = PaintPP::rectLine(SquareVertices, Size, vectorDireccion(true, false, true, false));
    imageCanvas = PaintPP::paintCoordinates(Square, imageCanvas,grossorE,colorSelect);
    return imageCanvas;
}





