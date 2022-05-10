#include "init_project/init_project.h"
#include "test/tester.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    InitProject::start(argc, argv);
    Tester::testMainWindow(argc, argv);
    return 0;
}
