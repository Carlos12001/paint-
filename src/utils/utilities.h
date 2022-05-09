//
// Created by carlo on 4/30/22.
//

#ifndef PAINT_UTILITIES_H
#define PAINT_UTILITIES_H
#include "iostream"
using namespace std;
#include <cstdlib>
#include <glog/logging.h>


class Utilities {

    static auto getIsStartedLog()-> bool&{
        static bool isStartedLog = false;
        return isStartedLog;
    };

public:
    static void callCow();

    static void startLog(char* argv[]);

    static void finishLog();
};


#endif //PAINT_UTILITIES_H
