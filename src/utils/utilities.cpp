//
// Created by carlo on 4/30/22.
//

#include "utilities.h"

void Utilities::callCow() {
    printMessageInfo("Hellow");
    system("cowsay Welcome to Paint++!");
}

void Utilities::printMessageInfo(string message) {
    cout << message << endl;
}

void Utilities::printMessageWarning(string message) {
    cout << message << endl;;
}

void Utilities::printMessageError(string message) {
    cerr << message << endl;;
}

void Utilities::printMessageFatal(string message) {
    cerr << message << endl;;
    exit(-1);
}
