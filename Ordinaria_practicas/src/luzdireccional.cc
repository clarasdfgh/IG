#include "luzdireccional.h"

LuzDireccional::LuzDireccional( const Tupla2f & orientacion, GLenum id_ , Tupla4f camb, Tupla4f cdif, Tupla4f cesp ){
    alpha = orientacion(X);
    beta  = orientacion(Y);

    id = id_;

    colorAmbiente = camb;
    colorDifuso = cdif;
    colorEspecular = cesp;

    float x = sin(alpha) * cos(beta);
    float y = sin(alpha) * cos(beta);
    float z = cos(alpha);

    posicion = {x, y, z, 0};
}
    

void LuzDireccional::variarAnguloAlpha( float incremento ){
   alpha += incremento;
   Tupla4f posicion_original = posicion;

   //Cuadrante positivo/negativo
   if (alpha > PI ){
      alpha = PI;

   } else if (alpha < -PI){
      alpha = PI;
   }

   posicion(0) = sin(alpha) * cos(beta) * sqrt(posicion_original.lengthSq());
   posicion(1) = sin(beta) * sin(alpha) * sqrt(posicion_original.lengthSq());
   posicion(2) = cos(alpha) * sqrt(posicion_original.lengthSq());
}

//Preguntar, me cuesta horrores el tema de las esféricas
void LuzDireccional::variarAnguloBeta ( float incremento ){
    beta += incremento;
    Tupla4f posicion_original = posicion;
    
   if (beta > PI ){
      beta = PI;

   } else if (beta < -PI){
      beta = -PI;
   }

   posicion(0) = sin(alpha) * cos(beta) * sqrt(posicion_original.lengthSq());
   posicion(1) = sin(alpha) * sin(beta) * sqrt(posicion_original.lengthSq());
   posicion(2) = cos(alpha) * sqrt(posicion_original.lengthSq());
}