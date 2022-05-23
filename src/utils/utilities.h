//
// Created by carlo on 4/30/22.
//

#ifndef PAINT_UTILITIES_H
#define PAINT_UTILITIES_H
#include "iostream"
using namespace std;
#include <cstdlib>

/**
 * THe class with method utils
 */
class Utilities {

public:

    /**
 * Call cow.
 */
    static void callCow();

/**
 * Print log messafe
 * @param message message
 */
    static void printMessageInfo(string message);
/**
 * PRint waarning
 * @param message warning
 */
    static void printMessageWarning(string message);


/**
 * PRint wrror
 * @param message the ererorr
 */
    static void printMessageError(string message);

    /**
 * PRint a fatal
 * @param message the fatal messagfe
 */
    static void printMessageFatal(string message);

};


#endif //PAINT_UTILITIES_H
