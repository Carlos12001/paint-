//
// Created by carlo on 4/30/22.
//

#include "tester.h"
#include "QApplication"
#include "gui/controller.h"

int Tester::testMainWindow(int argc, char **argv) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
