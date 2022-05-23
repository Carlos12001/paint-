//
// Created by carlo on 4/30/22.
//

#include "init_project.h"
#include "utils/utilities.h"
#include "test/tester.h"

/**
 * init the project
 * @param argc argument number
 * @param argv the argument
 */
void InitProject::start(int argc, char* argv[]) {
    QApplication app =  QApplication(argc, argv);
    MainWindow w;
    w.initGUIPaintPP();
    w.show();
    app.exec();
}
