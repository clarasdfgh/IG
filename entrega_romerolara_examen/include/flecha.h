#ifndef FLECHA_H_INCLUDED
#define FLECHA_H_INCLUDED

#include "auxiliar.h"
#include "objrevolucion.h"

//EXAMEN EJERCICIO 2
class Flecha : public ObjRevolucion{
private:
    float altura_punta;
    float altura_cuerpo;

public: 
    Flecha ( 
        const int n_rev , 
        const int h_punta , 
        const float h_cuerpo);
} ;

#endif