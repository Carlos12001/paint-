//
// Created by joan on 15/05/22.
//

#ifndef PAINT_VECTORMOVEMENT_H
#define PAINT_VECTORMOVEMENT_H


struct vectorMovement {
    int PosX;
    int PosY;

    vectorMovement();
    vectorMovement(int PosX, int PosY);
};
struct vectorDireccion{
    bool Right;
    bool Up;
    bool Horizontal;
    bool Vertical;
    vectorDireccion();
    vectorDireccion(bool Right, bool Up, bool Horizontal, bool Vertical);
};


#endif //PAINT_VECTORMOVEMENT_H
