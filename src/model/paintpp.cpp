//
// Created by carlo on 5/3/22.
//

#include "paintpp.h"

void PaintPP::createImage(){
    historyImage->append(&historyImage, getNextHistoryName());
    currentImage = Image::createImageEmpty(1280,720);
    return;
}

vectorStructure<Color> PaintPP::getCurrentImage() {
    if(currentImage == nullptr){
        Utilities::printMessageError("No exist current image. "
                                     "I'm going to create the default image.");
        createImage();
    }
    return currentImage->getColors();
}

string PaintPP::getNextHistoryName(){
    return string("canvas_") + to_string(++counterImage) + string(".bmp");
}

PaintPP::~PaintPP() {

}
