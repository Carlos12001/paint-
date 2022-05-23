//
// Created by carlo on 4/30/22.
//

#include "utilities.h"

/**
 * Call cow.
 */
void Utilities::callCow() {
    printMessageInfo("Hellow");
    system("cowsay Welcome to Paint++!");
}

/**
 * Print log messafe
 * @param message message
 */
void Utilities::printMessageInfo(string message) {
//    cout << message << endl;
}

/**
 * PRint waarning
 * @param message warning
 */
void Utilities::printMessageWarning(string message) {
    cout << message << endl;;
}

/**
 * PRint wrror
 * @param message the ererorr
 */
void Utilities::printMessageError(string message) {
    cerr << message << endl;;
}

/**
 * PRint a fatal
 * @param message the fatal messagfe
 */
void Utilities::printMessageFatal(string message) {
    cerr << message << endl;;
    exit(-1);
}
