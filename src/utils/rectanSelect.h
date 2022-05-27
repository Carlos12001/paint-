//
// Created by joan on 26/05/22.
//

#ifndef PAINT_RECTANSELECT_H
#define PAINT_RECTANSELECT_H
#include "utils/doublyLinkedList.h"
#include "utils/vectorStructure.h"
#include "utils/utilities.h"
#include "model/image.h"
#include <fstream>
#include "model/point_image.h"
#include <math.h>
#include "model/paintpp.h"
class rectanSelect{
public:
    auto static rectangleSelect(vectorStructure<PointImage> vectorTwoCordinates, Image *imageCanvas, int grossorE) -> Image * {
        Color colorSelect = Color(128,128,128,128);
        int distancex = 0;
        int distancey = 0;
        if(vectorTwoCordinates.getElement(0).x < vectorTwoCordinates.getElement(1).x){
            distancex = vectorTwoCordinates.getElement(1).x-vectorTwoCordinates.getElement(0).x;
        }else{
            distancex = vectorTwoCordinates.getElement(0).x - vectorTwoCordinates.getElement(1).x;
        }
        if(vectorTwoCordinates.getElement(0).y < vectorTwoCordinates.getElement(1).y){
            distancey = vectorTwoCordinates.getElement(1).y-vectorTwoCordinates.getElement(0).y;
        }else{
            distancey = vectorTwoCordinates.getElement(0).y - vectorTwoCordinates.getElement(1).y;
        }

        vectorStructure<PointImage> Move = rectLine(vectorTwoCordinates,distancex,distancey);
        imageCanvas = PaintPP::pencil(Move,imageCanvas,grossorE,colorSelect);
        return imageCanvas;
    }
    static vectorStructure<PointImage>rectLine(vectorStructure<PointImage> coordinates, int distancex, int distancey) {
        vectorStructure<PointImage> allCoordinates;
        vectorStructure<PointImage> temp;
        temp = coordinates;
        if(coordinates.getElement(0).x < coordinates.getElement(1).x){
        while(distancex > 0){
            //Utilities::printMessageInfo("x1: " + to_string(temp.getElement(0).x));
            //Utilities::printMessageInfo("x2: " + to_string(coordinates.getElement(1).x));
            allCoordinates.addElement(PointImage(temp.getElement(0).x, temp.getElement(0).y));
            allCoordinates.addElement(PointImage(temp.getElement(1).x, temp.getElement(1).y));
            temp.addElement(PointImage(temp.getElement(0).x + 1, temp.getElement(0).y), 0);
            temp.addElement(PointImage(temp.getElement(1).x - 1, temp.getElement(1).y), 1);
            distancex -= 1;
        }}else{
            while(distancex > 0) {
                allCoordinates.addElement(PointImage(temp.getElement(0).x, temp.getElement(0).y));
                allCoordinates.addElement(PointImage(temp.getElement(1).x, temp.getElement(1).y));
                temp.addElement(PointImage(temp.getElement(1).x+1,temp.getElement(1).y),1);
                temp.addElement(PointImage(temp.getElement(0).x-1,temp.getElement(0).y),0);
                distancex -= 1;
        }}
        temp = coordinates;
        if(coordinates.getElement(0).y < coordinates.getElement(1).y){
        while(distancey > 0){
            Utilities::printMessageInfo("y1: " + to_string(temp.getElement(0).y));
            Utilities::printMessageInfo("y2: " + to_string(temp.getElement(1).y));
            allCoordinates.addElement(PointImage(temp.getElement(0).x,temp.getElement(0).y));
            allCoordinates.addElement(PointImage(temp.getElement(1).x,temp.getElement(1).y));

            temp.addElement(PointImage(temp.getElement(0).x,temp.getElement(0).y+1),0);
            temp.addElement(PointImage(temp.getElement(1).x,temp.getElement(1).y-1),1);
            distancey -= 1;
            }}else{
            while(distancey > 0) {

                allCoordinates.addElement(PointImage(temp.getElement(0).x,temp.getElement(0).y));
                allCoordinates.addElement(PointImage(temp.getElement(1).x,temp.getElement(1).y));
                temp.addElement(PointImage(temp.getElement(1).x, temp.getElement(1).y + 1), 1);
                temp.addElement(PointImage(temp.getElement(0).x, temp.getElement(0).y - 1), 0);
                distancey -= 1;
            }
        }
        return allCoordinates;
    }
};

#endif //PAINT_RECTANSELECT_H
