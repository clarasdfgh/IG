#ifndef TORSO_H_INCLUDED
#define TORSO_H_INCLUDED

#include "auxiliar.h"
#include "cilindro.h"
#include "esfera.h"

//Cilindro+Esfera, incluye la cabeza porque esta no tiene movimientos específicos

class Torso: public Malla3D
{
   public:
      Cilindro * torso = nullptr;
      Esfera * cabeza  = nullptr;
      float r, h;
      float angulo = 0;

      Torso(float _r, float _h);
      void rotar (float incr);
      void draw(int c);

} ;




#endif
