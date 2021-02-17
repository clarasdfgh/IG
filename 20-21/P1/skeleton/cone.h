/*! \file
    Clara María Romero
    3ºB -- Informática Gráfica 20-21
    Práctica 2: Objetos PLY y modelos poligonales
*/

#ifndef CONE_H
#define CONE_H


#include "object_revolution.h"

class _cone:public object_revolution
{
public:
    _cone(const int iterations, const float Size=1.0, const float radius=0.5, const bool lid=true, const axis rotation_axis=Y_AXIS);
    float Size;
    float radius;
};


#endif
