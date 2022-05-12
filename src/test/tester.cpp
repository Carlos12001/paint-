//
// Created by carlo on 4/30/22.
//

#include "tester.h"
#include "QApplication"
#include "gui/controller.h"
#include "utils/vectorStructure.h"
#include "utils/vectorStructure.cpp"
#include "utils/doublyLinkedList.h"

#include <iostream>
using namespace std;


int Tester::testMainWindow(int argc, char **argv) {
    doublyLinkedList<int>* linkedtest;
    vectorStructure<int> vectest;
    linkedtest->append(&linkedtest,3);
    linkedtest->insertNode(&linkedtest, 6);
    linkedtest->printList(linkedtest);
    vectest.addElement(3);
    vectest.showVector();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}