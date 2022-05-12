//
// Created by carlo on 4/30/22.
//

#include "tester.h"
#include "QApplication"
#include "gui/controller.h"
#include "utils/vectorStructure.h"
#include "utils/vectorStructure.cpp"


#include <iostream>
using namespace std;


int Tester::testMainWindow(int argc, char **argv) {
    vectorStructure<int> vectest;
    vectest.addElement(3);
    vectest.showVector();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}