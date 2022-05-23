//
// Created by joan on 09/05/22.
//
#ifndef PAINT_VECTORSTRUCTURE_H
#define PAINT_VECTORSTRUCTURE_H
#include <iostream>
using namespace std;


template <typename T>
class vectorStructure {
private:
    T *addressVector;
    int storageCapacity;
    int numberOfElement;

public:
    /*
     * Create a vector Structure with defect data.
     */
    vectorStructure(){
        addressVector = new T[1];
        storageCapacity = 1;
        numberOfElement = 0;
    };
    void addElement(T data){
        {
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
    };
    /*
     * Add element to the vector that you create
     */
    void addElement(T data, int location){
        if(location == numberOfElement) {
            addElement(data);
        }else {
            addressVector[location] = data;
        }
    };
    /**
     * get the element to the location that give, is work with index
     * @param elementLocation
     * @return
     */
    T getElement(int elementLocation){
        if(elementLocation < numberOfElement) {
            return addressVector[elementLocation];
        }
        else{
            exit(-1);
        }
    };
    /**
     * delete the last element that give
     */
    void pop(){
        numberOfElement --;
    };
    /**
     * return the size of the vector
     * @return
     */
    int size(){
        return numberOfElement;
    };
    /**
     * return the capacity of the vector
     * @return
     */
    int getCapacity(){
        return storageCapacity;
    };
    /**
     * print the vector entire.
     */
    void showVector(){
        for(int index = 0; index<numberOfElement; index++){
            cout << addressVector[index] << "";
        }
        cout << endl;
    };
};

#endif //PAINT_VECTORSTRUCTURE_H
