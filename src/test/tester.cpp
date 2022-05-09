//
// Created by carlo on 4/30/22.
//

#include "tester.h"
#include <QApplication>
#include "gui/controller.h"
#include <iostream>
#include <glog/logging.h>
using namespace std;

int Tester::testMainWindow(int argc, char **argv) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

void Tester::bmpImageTest1() {
    long size = 1200*750;
    unsigned char sizeChar[4];
    sizeChar[0] = size;
    sizeChar[1] = size >> 8;
    sizeChar[2] = size >> 16;
    sizeChar[3] = size >> 24;

    LOG(INFO) << "size = " << size << endl;
    LOG(INFO) << "sizeChar[0] = " << +sizeChar[0] << endl;
    LOG(INFO)  << "sizeChar[1] = " << +(size >> 8) << endl;
    LOG(INFO)  << "sizeChar[1] = " << +sizeChar[1] << endl;
    LOG(INFO)  << "sizeChar[2] = " << +sizeChar[2] << endl;
    LOG(INFO)  << "sizeChar[3] = " << +sizeChar[3] << endl;
    LOG(INFO)  << "sizeChar =\t" << +sizeChar[0] << "\t" << +sizeChar[1] << "\t" << +sizeChar[2] << "\t" << +sizeChar[3] << endl;

    LOG(INFO)  << +((unsigned char ) 255) << endl;
}
