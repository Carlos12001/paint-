#include "init_project/init_project.h"
#include "test/tester.h"

int main(int argc, char *argv[]) {
    InitProject::start();
    Tester::testMainWindow(argc, argv);
    return 0;
}
