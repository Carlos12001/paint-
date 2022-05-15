//
// Created by carlo on 5/3/22.
//

#include "paintpp.h"

PaintPP::PaintPP(int width, int height) {
    createEmptyCanvas(width, height);
}

PaintPP::PaintPP(string pathImage) {
    createImageCanvas(pathImage);
}

void PaintPP::createEmptyCanvas(int width, int height){
    historyImage->append(&historyImage, getNextHistoryName());
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
    historyImage->append(&historyImage, getNextHistoryName());
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
    return string("canvas_") + to_string(++counterImage) + string(".bmp");
}

PaintPP::~PaintPP() {

}

int PaintPP::getWidthCanvas(){
    return currentImage->getWidth();
}

int PaintPP::getHeightCanvas(){
    return currentImage->getHeight();
}

void PaintPP::saveImage(){
    auto path = historyImage->data;
    currentImage->exportImage(path);
}