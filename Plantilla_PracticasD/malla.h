// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Malla3D
{
   public:

   GLuint crearVBO(GLuint tipo_vbo, GLuint tam, GLvoid * puntero_ram);
   
   // función que dibuja el objeto en modo diferido (usando VBOs)
   void draw() ;

   protected:



   std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   std::vector<Tupla3i> f ;   // una terna de 3 enteros por cada cara o triángulo
   std::vector<Tupla3i> c ;   // P1: tabla de colores
   
   // Completar P1: vbo y método asociado
   GLuint id_vbo_v = 0;
   GLuint id_vbo_f = 0;
   GLuint id_vbo_c = 0;

} ;


#endif
