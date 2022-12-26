#ifndef LUZ_DIR_INCLUDED
#define LUZ_DIR_INCLUDED

#include "auxiliar.h"
#include "luz.h"

class LuzDireccional : public Luz{
protected: 
    float alpha ; 
    float beta ; 
    
public : 
    // inicializar la fuente de luz 
    LuzDireccional ( const Tupla2f & orientacion, GLenum id_ , Tupla4f camb, Tupla4f cdif, Tupla4f cesp ) ; 

    // Cambiar ángulo: 
    void variarAnguloAlpha( float incremento ) ; 
    void variarAnguloBeta ( float incremento ) ; 
    
};

#endif