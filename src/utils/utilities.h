//
// Created by carlo on 4/30/22.
//

#ifndef PAINT_UTILITIES_H
#define PAINT_UTILITIES_H
#include "iostream"
using namespace std;
#include <cstdlib>


class Utilities {

    static auto getIsStartedLog()-> bool&{
        static bool isStartedLog = false;
        return isStartedLog;
    };

public:
    static void callCow();

    static void printMessageInfo(string message);

    static void printMessageWarning(string message);

    static void printMessageError(string message);

    static void printMessageFatal(string message);

};


#endif //PAINT_UTILITIES_H
