//
// Created by carlo on 4/30/22.
//

#include "init_project.h"
#include "utils/utilities.h"
#include "test/tester.h"
/**
 * gasdjdsjvpioxbnljd
 * @param argc
 * @param argv
 */
void InitProject::start(int argc, char* argv[]) {
    QApplication app =  QApplication(argc, argv);
    MainWindow w;
    w.initGUIPaintPP();
    w.show();
    app.exec();
}
