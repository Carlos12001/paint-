//
// Created by carlo on 4/30/22.
//

#include "init_project.h"
#include "utils/utilities.h"
#include "test/tester.h"
void InitProject::start(int argc, char* argv[]) {
    Utilities::startLog(argv);

    Utilities::finishLog();
}
