//
// Created by carlo on 4/30/22.
//

#ifndef PAINT_TESTER_H
#define PAINT_TESTER_H
#include "utils/vectorStructure.h"
#include <iostream>
#include "QApplication"
#include "gui/controller.h"
#include <iostream>
using namespace std;
#include "model/image.h"
class Tester {
public:

    [[maybe_unused]] static int testMainWindow(int argc, char* argv[]);

    [[maybe_unused]] static void bmpImageTest1();

    static void bmpImageTest2();

    [[maybe_unused]] static void bmpImageTest3();
};


#endif //PAINT_TESTER_H
