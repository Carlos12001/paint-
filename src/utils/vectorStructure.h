//
// Created by joan on 09/05/22.
//
#ifndef PAINT_VECTORSTRUCTURE_H
#define PAINT_VECTORSTRUCTURE_H


template <typename T>
class vectorStructure {
private:
    T *addressVector;
    int storageCapacity;
    int numberOfElement;

public:
    vectorStructure();
    void addElement(T data);
    void addElement(T data, int location);
    T getElement(int elementLocation);
    void pop();
    int size();
    int getCapacity();
    void showVector();
};

#endif //PAINT_VECTORSTRUCTURE_H
