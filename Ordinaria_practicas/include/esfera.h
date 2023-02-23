#ifndef ESFERA_H_INCLUDED
#define ESFERA_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"


class Esfera : public ObjRevolucion{
private:
    float radio;
    

public: 
    Esfera ( 
        const int m , 
        const int n , 
        const float h , 
        const float r );
} ;

#endif