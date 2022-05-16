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

[[maybe_unused]] void Tester::deleteNullPointers(){
    int* ptr = new int(12);
    int* ptr2 = nullptr;
    int* ptr3 = NULL;
    delete ptr;
    delete ptr2;
    delete ptr3;
    Utilities::printMessageInfo("All good.");
    return;
}

[[maybe_unused]] int Tester::programWindow(int argc, char **argv) {
    QApplication app =  QApplication(argc, argv);
    MainWindow w;
    w.initGUIPaintPP();
    w.show();
    return app.exec();
}

[[maybe_unused]] void Tester::testPopVectorMove() {
    vectorStructure<int> vectorMove;
    while (vectorMove.size()!=0){
        vectorMove.pop();
        cout << "Deleting an element\t";
    }
}
