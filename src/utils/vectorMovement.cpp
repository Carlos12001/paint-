//
// Created by joan on 15/05/22.
//

#include "vectorMovement.h"

vectorMovement::vectorMovement():PosX(0), PosY(0){}

vectorMovement::vectorMovement(int PosX, int PosY):PosX(PosX), PosY(PosY) {}

vectorDireccion::vectorDireccion():Right(false),Up(false) , Horizontal(false), Vertical(false){}

vectorDireccion::vectorDireccion(bool Right, bool Up, bool Horizontal, bool Vertical):Right(Right), Up(Up),
                                Horizontal(Horizontal),Vertical(Vertical) {}
