//
// Created by carlo on 5/3/22.
//

#include "paintpp.h"
#include "utils/vectorStructure.h"

auto PaintPP::erase(vectorStructure<int> VectorX, vectorStructure<int> VectorY, Image* imageCanvas, int grossorE)->Image*{
    int WIDTH = imageCanvas->getWidth();
    int HEIGHT = imageCanvas->getHeight();
    Utilities::printMessageInfo(to_string(VectorX.size()) + " y: " + to_string(VectorY.size()));
    for(int index = 0; index < VectorX.size(); index++){
        int elementY = VectorY.getElement(index);
        int elementX = VectorX.getElement(index);
        Utilities::printMessageInfo("Erase pixel: y: "
                                    + to_string(elementY) + " x: "
                                    + to_string(elementX));
        for(int applyG = 0; applyG < grossorE; applyG++) {
            if(elementX+applyG < WIDTH && elementX+applyG > 0
                    && elementX+applyG < VectorX.getElement(VectorX.size()-1)) {
                imageCanvas->setColor(Color(255, 255, 255, 255),
                                      (elementX + applyG),
                                      (elementY));
            }
            if(elementX - applyG < WIDTH && elementX - applyG > 0
                    && elementX-applyG > VectorX.getElement(VectorX.size()-1)){
                imageCanvas->setColor(Color(255, 255, 255, 255),
                                      (elementX - applyG),
                                      (elementY));
            }
        }
        for(int applyGY = 0; applyGY < grossorE; applyGY++) {
            if(elementY+applyGY < HEIGHT && elementY+applyGY > 0
            && elementY+applyGY < VectorY.getElement(VectorY.size()-1)){
                imageCanvas->setColor(Color(255, 255, 255, 255),
                                      (elementX),
                                      (elementY + applyGY));
            }
            if(elementY - applyGY < HEIGHT && elementY - applyGY > 0
            && elementY-applyGY > VectorY.getElement(VectorY.size()-1)){
                imageCanvas->setColor(Color(255, 255, 255, 255),
                                      (elementX),
                                      (elementY - applyGY));
            }
        }
    }
    return imageCanvas;
}

vectorStructure<int> PaintPP::mouseMovement(int position) {
    vectorStructure<int> eraseMoveX;
    for(int startPosX = 300; startPosX < position; startPosX++)
        eraseMoveX.addElement(startPosX);
    return eraseMoveX;
}
