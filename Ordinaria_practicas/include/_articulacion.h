#ifndef ARTICULACION_H_INCLUDED
#define ARTICULACION_H_INCLUDED

#include "auxiliar.h"
#include "cilindro.h"
#include "esfera.h"

//Esfera+Cilindro, que gira con la esfera como bisagra

class Articulacion: public Malla3D
{
   public:
      Cilindro * cil = nullptr ;
      Esfera * esf   = nullptr;
      float angulo = 0;
      float h, r;

      Articulacion(float _r, float _h);     //Como parámetros recibe el radio (esfera y cilindro), y la altura del cilindro
      void rotar(float incr);
      void draw(int c);

} ;




#endif
