// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef CUBO_H_INCLUDED
#define CUBO_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 v y 6 caras)

class Cubo : public Malla3D
{
   public:
   Cubo(float l=1) ;

   Tupla3f colorsel = {0,1.0,0};

   inline Tupla3f getColorSel(){ return colorsel; };

} ;




#endif
