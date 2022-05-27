//
// Created by carlo on 4/30/22.
//

#ifndef PAINT_TESTER_H
#define PAINT_TESTER_H
#include "utils/vectorStructure.h"
#include <iostream>
#include "QApplication"
#include "gui/controller.h"
#include "model/paintpp.h"
#include "utils/bfsPaintFill.h"
#include "utils/MagicSelect.h"
#include <iostream>
using namespace std;
#include "model/image.h"
class Tester {
public:

    [[maybe_unused]] static int testMainWindow(int argc, char* argv[]);

    [[maybe_unused]] static void bmpImageTest1();

    [[maybe_unused]] static void bmpImageTest2();

    [[maybe_unused]] static void bmpImageTest3();

    [[maybe_unused]] static void bmpImageTest4();

    [[maybe_unused]] static int programWindow(int argc, char **argv);

    [[maybe_unused]] static void testPopVectorMove();

    [[maybe_unused]] static void deleteNullPointers();

    [[maybe_unused]] static void eraseImageTest1();

    [[maybe_unused]] static void BFSTest();

    [[maybe_unused]] static void testEraseListDouble();
};


#endif //PAINT_TESTER_H
