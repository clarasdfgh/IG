#include "luzdireccional.h"

LuzDireccional::LuzDireccional( const Tupla2f & orientacion, const Tupla3f & p, GLenum id_ , Tupla4f camb, Tupla4f cdif, Tupla4f cesp ){
    alpha = orientacion(X);
    beta  = orientacion(Y);

    id = id_;

    colorAmbiente = camb;
    colorDifuso = cdif;
    colorEspecular = cesp;


    posicion = {p(X), p(Y), p(Z), 1};
}
    

void LuzDireccional::variarAnguloAlpha( float incremento ){
   alpha += incremento;
   Tupla4f posicion_original = posicion;

   if (alpha > PI*2.0 ){
      alpha -= PI*2.0;

   } else if (alpha < 0){
      alpha += PI*2.0;
   }

   posicion(0) = sin(alpha) * cos(beta) * sqrt(posicion_original.lengthSq());
   posicion(1) = sin(beta) * sqrt(posicion_original.lengthSq());
   posicion(2) = cos(alpha) * cos(beta) * sqrt(posicion_original.lengthSq());
}


void LuzDireccional::variarAnguloBeta ( float incremento ){
    beta += incremento;
    Tupla4f posicion_original = posicion;
    
   if (beta > PI/2.0 ){
      beta = PI/2.0;

   } else if (beta < -(PI/2.0)){
      beta = -(PI/2.0);
   }

   posicion(0) = sin(alpha) * cos(beta) * sqrt(posicion_original.lengthSq());
   posicion(1) = sin(beta) * sqrt(posicion_original.lengthSq());
   posicion(2) = cos(beta) * cos(alpha) * sqrt(posicion_original.lengthSq());
}