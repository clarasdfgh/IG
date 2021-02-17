/*! \file
    Clara María Romero
    3ºB -- Informática Gráfica 20-21
    Práctica 2: Objetos PLY y modelos poligonales
*/
#include "cone.h"
#include "object_revolution.h"

_cone::_cone(const int iterations, const float Size, const float radius, const bool lid, const axis eje)
{
    switch(eje){
        case X_AXIS:
            profile.push_back({0,0,0});
            profile.push_back({0,radius,0});
            profile.push_back({Size,0,0});
        break;

        case Y_AXIS:
            profile.push_back({0,0,0});
            profile.push_back({radius,0,0});
            profile.push_back({0,Size,0});
        break;

        case Z_AXIS:
            profile.push_back({0,0,0});
            profile.push_back({0,radius,0});
            profile.push_back({0,0,Size});
        break;
    }

    this->iterations = iterations;
    this->bottom_lid = lid;
    this->Size = Size;
    this->radius = radius;
    this->eje = eje;

    this->top_lid = false;

    make_object(/*profile,*/eje);
}
