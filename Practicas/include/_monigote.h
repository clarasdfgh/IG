#ifndef MONIGOTE_H_INCLUDED
#define MONIGOTE_H_INCLUDED

#include "auxiliar.h"
#include "_articulacion.h"
#include "_torso.h"

class Monigote: public Malla3D
{
   public:
      Articulacion * musloizdo   = nullptr;
      Articulacion * muslodcho   = nullptr;
      Articulacion * gemeloizdo  = nullptr;
      Articulacion * gemelodcho  = nullptr;

      Articulacion * hombroizdo  = nullptr;
      Articulacion * hombrodcho  = nullptr;
      Articulacion * codoizdo    = nullptr;
      Articulacion * cododcho    = nullptr;

      Torso * torso              = nullptr;

      Cilindro * palo            = nullptr;

      Tupla3f colorsel = {1.0,0,0};
      
      float r_brazo  = 5;
      float r_pierna = 7;
      float r_torso  = 15;

      float h_brazo  = 13;
      float h_pierna = 17;
      float h_torso  = 28;

      float a_musloizdo    = 0;
      float a_muslodcho    = 0;
      float a_gemeloizdo   = 0;
      float a_gemelodcho   = 0;
      float a_hombroizdo   = 0;
      float a_hombrodcho   = 0;
      float a_codoizdo     = 0;
      float a_cododcho     = 0;
      float a_torso        = 0;
      
      float a_palo         = 0;
      
      float a_pos          = 0;
      float a_pospalo      = 0; 

      

      Monigote();
      void restaurarPos();

      inline void modMusloIzdo(float incr){ a_musloizdo+=incr; };
      inline void modMusloDcho(float incr){ a_muslodcho+=incr; };
      inline void modGemeloIzdo(float incr){ a_gemeloizdo+=incr; };
      inline void modGemeloDcho(float incr){ a_gemelodcho+=incr; };
      inline void modHombroIzdo(float incr){ a_hombroizdo+=incr; };
      inline void modHombroDcho(float incr){ a_hombrodcho+=incr; };
      inline void modCodoIzdo(float incr){ a_codoizdo+=incr; };
      inline void modCodoDcho(float incr){ a_cododcho+=incr; };
      inline void modTorso(float incr){ a_torso+=incr; };
      inline void modPalo(float incr){ a_palo+=incr; };

      inline void modPos(float incr){ a_pos+=incr; };
      inline void modPosPalo(float incr){ a_pospalo+=incr; };

      inline Tupla3f getColorSel(){ return colorsel; };

      void draw(int c);
} ;






#endif