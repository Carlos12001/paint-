//
// Created by joan on 09/05/22.
//
#include "vectorStructure.h"
#include <iostream>
using namespace std;
template<typename T>
vectorStructure<T>::vectorStructure(){
    cout << "Creando Objeto"<< endl;
    addressVector = new T[1];
    storageCapacity = 1;
    numberOfElement = 0;
}
template<typename T>
void vectorStructure<T>::addElement(T data) {
    if(numberOfElement == storageCapacity){
        T* temp = new T[2*storageCapacity];

        for(int index = 0; index < storageCapacity;index++){
            temp[index] = addressVector[index];
        }
        delete[] addressVector;
        storageCapacity *= 2;
        addressVector = temp;
    }
    addressVector[numberOfElement] = data;
    numberOfElement++;
}
template<typename T>
void vectorStructure<T>::addElement(T data, int location) {
    if(location == numberOfElement) {
        addElement(data);
    }else {
        addressVector[location] = data;
    }
}
template<typename T>
T vectorStructure<T>::getElement(int elementLocation) {
    if(elementLocation < numberOfElement) {
        return addressVector[elementLocation];
    }
}
template<typename T>
void vectorStructure<T>::pop() {
    numberOfElement --;
}
template<typename T>
int vectorStructure<T>::size() {
    return numberOfElement;
}
template<typename T>
int vectorStructure<T>::getCapacity() {
    return storageCapacity;
}
template<typename T>
void vectorStructure<T>::showVector() {
    for(int index = 0; index<numberOfElement; index++){
        cout << addressVector[index] << "";
    }
    cout << endl;
}

