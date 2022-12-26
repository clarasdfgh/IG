#ifndef ARTICULACION_H_INCLUDED
#define ARTICULACION_H_INCLUDED

#include "auxiliar.h"
#include "cilindro.h"
#include "esfera.h"

//Esfera+Cilindro, que normalmente gira con la esfera como bisagra

class Articulacion: public Malla3D
{
   public:
      Articulacion(float r, float h);
      void draw();

} ;




#endif
