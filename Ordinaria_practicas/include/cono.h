#ifndef CONO_H_INCLUDED
#define CONO_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"


class Cono : public ObjRevolucion{
private:
    float altura;
    float radio;

public: 
    Cono ( 
        const int num_vert_perfil , 
        const int n , 
        const float h , 
        const float r );
} ;

#endif