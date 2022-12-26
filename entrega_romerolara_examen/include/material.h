#ifndef MATERIAL_INCLUDED
#define MATERIAL_INCLUDED

#include "auxiliar.h"


class Material { 
private : 
    Tupla4f difuso = {1.0, 0.0, 0.0, 1.0}; 
    Tupla4f especular = {0.0, 1.0, 0.0, 1.0}; 
    Tupla4f ambiente = {0.0, 0.0, 1.0, 1.0}; 
    float brillo = 0.5; 
    
public : 
    Material ();
    Material ( Tupla4f mdifuso , Tupla4f mespecular , Tupla4f mambiente , float brillo_ ); 
    void aplicar (); 
};

#endif