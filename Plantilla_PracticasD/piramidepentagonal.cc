#include "auxiliar.h"
#include "malla.h"
#include "piramidepentagonal.h"

PiramidePentagonal::PiramidePentagonal(float h, float r)
{
   const float PI = 2*acos(0.0);
   const float DEG_TO_RAD = PI/180;

   float lado = 2 * r * cos(DEG_TO_RAD*36);

   float x1 = lado * cos(DEG_TO_RAD*54);
   float z1 = r * cos(DEG_TO_RAD*18);

   float x2 = lado/2;
   float z2 = r * cos(DEG_TO_RAD*54);

   // P1: inicializar la tabla de vértices
   v[0] = Tupla3f(0, h, 0);

   v[1] = Tupla3f(0, 0, -r);

   v[2] = Tupla3f(-x1, 0, -z1);
   v[3] = Tupla3f(x1, 0, -z1);

   v[4] = Tupla3f(-x2, 0, z2);
   v[5] = Tupla3f(x2, 0, z2);

   // P1: inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior)
   f[0] = Tupla3i(0,4,5);
   f[1] = Tupla3i(0,5,3);
   f[2] = Tupla3i(0,3,1);
   f[3] = Tupla3i(0,1,2);
   f[4] = Tupla3i(0,2,4);

   f[5] = Tupla3i(1,3,2);
   f[6] = Tupla3i(2,3,4);
   f[7] = Tupla3i(3,5,4);

   // inicializar la/s tabla/s de colores
   
}

