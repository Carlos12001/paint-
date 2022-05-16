//
// Created by carlo on 4/30/22.
//

#include "tester.h"
#include <iostream>
using namespace std;


[[maybe_unused]] int Tester::testMainWindow(int argc, char **argv) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}

[[maybe_unused]] void Tester::bmpImageTest1() {
//    long size = 1200*750;
//    unsigned char sizeChar[4];
//    sizeChar[0] = size;
//    sizeChar[1] = size >> 8;
//    sizeChar[2] = size >> 16;
//    sizeChar[3] = size >> 24;
//
//    LOG(INFO) << "size = " << size;
//    LOG(INFO) << "sizeChar[0] = " << +sizeChar[0];
//    LOG(INFO)  << "sizeChar[1] = " << +(size >> 8);
//    LOG(INFO)  << "sizeChar[1] = " << +sizeChar[1];
//    LOG(INFO)  << "sizeChar[2] = " << +sizeChar[2];
//    LOG(INFO)  << "sizeChar[3] = " << +sizeChar[3];
//    LOG(INFO)  << "sizeChar =\t" << +sizeChar[0] << "\t" << +sizeChar[1] << "\t" << +sizeChar[2] << "\t" << +sizeChar[3];
//
//    LOG(INFO)  << +((unsigned char ) 255) ;
    return;
}

[[maybe_unused]] void Tester::bmpImageTest2() {
    Utilities::printMessageInfo("Trying to create image object.");

    int widthC = 1280;
    int heightC = 720;
    auto imageN = Image::createImageEmpty(widthC,heightC);

    Utilities::printMessageInfo(string("Creating an image with the size ") + to_string(imageN->getWidth()) + string("x")  + to_string(imageN->getHeight()));
    imageN->exportImage("canvas.bmp");
    return;
}

[[maybe_unused]] void Tester::bmpImageTest3() {
    int widthC = 1280;
    int heightC = 720;
    for (int j = 0; j < heightC; ++j) {
        for (int i = 0; i < widthC; ++i) {
            cout << i << "," << j << "\t";
        }
        cout << endl;
    }
}

[[maybe_unused]] void Tester::bmpImageTest4() {
    string path = "ai-hayasaka.bmp";
    string path2  = "canvas2.bmp";
    string path3  = "canvas3.bmp";
    string path4  = "canvas4.bmp";
    Utilities::printMessageInfo("Trying to load image. The path is " + path);
    auto image = Image::createImageEmpty(1, 2);
    image->exportImage(path2);

    auto imageN = Image::readImage(path);
    imageN->exportImage(path3);

    auto imageM = Image::readImage(path3);
    imageM->exportImage(path4);
    return;
}

[[maybe_unused]]void Tester::eraseImageTest1(){
    string path1 = "canvas3.bmp";
    auto ImageEdit = Image::readImage(path1);
    Utilities::printMessageInfo("Trying to erase a part of the image. The path is " + path1);
    vectorStructure<vectorMovement> Move = PaintPP::mouseMovement(700,700);
    vectorStructure<vectorMovement> Line;
    Line.addElement(vectorMovement(40,10));
    Line.addElement(vectorMovement(40,200));
    auto image5 = PaintPP::pencil(Move,ImageEdit,20,Color(0,255,0));
    image5 = PaintPP::pen(Line,image5,10,Color(5,25,0));
    image5 = PaintPP::erase(Move,image5,10);
    image5 = PaintPP::figureSquare(vectorMovement(400,400),image5,5,Color(10,10,10),200);
    image5->exportImage("canvas5.bmp");
}