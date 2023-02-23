#include "auxiliar.h"
#include "malla.h"
#include "cubo.h"

Cubo::Cubo(float lado)
{
   float l = lado/2;

   // P1: inicializar la tabla de vértices
   // Recordamos que la base está centrada en el eje de coordenadas
   v.resize(8);
   v[0] = Tupla3f(l, 0, l);
   v[1] = Tupla3f(l, 0, -l);
   v[2] = Tupla3f(-l, 0, -l);
   v[3] = Tupla3f(-l, 0, l);
   v[4] = Tupla3f(l, lado, l);
   v[5] = Tupla3f(l, lado, -l);
   v[6] = Tupla3f(-l, lado, -l);
   v[7] = Tupla3f(-l, lado, l);


   // P1: inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   f.resize(12);
   f[0] = Tupla3i(3,0,4);
   f[1] = Tupla3i(3,4,7);

   f[2] = Tupla3i(0,1,5);
   f[3] = Tupla3i(0,5,4);

   f[4] = Tupla3i(2,5,1);
   f[5] = Tupla3i(2,6,5);

   f[6] = Tupla3i(3,6,2);
   f[7] = Tupla3i(3,7,6);

   f[8] = Tupla3i(7,4,5);
   f[9] = Tupla3i(7,5,6);

   f[10] = Tupla3i(1,3,2);
   f[11] = Tupla3i(1,0,3);

    setColorSeleccion(getColorSel());
    setColor();
}


void Cubo::setColor(){
    for(int i=0; i<v.size();i++){
        c[0].push_back(c_puntos);
        c[1].push_back(c_linea);
    }

    //EXAMEN EJ1: la esquina 0,0,0 se corresponde al color negro. La esquina l,l,l se corresponde al blanco (1,1,1).
    //El eje X corresponde al color verde
    //El eje Z corresponde al color rojo
    //El eje Y corresponde al color azul
    c[2].resize(8);
    c[2][0]={1,0,1}; //+x-y+z
    c[2][1]={1,0,0}; //+x-y-z
    c[2][2]={0,0,0}; //-x-y-z
    c[2][3]={0,0,1}; //-x-y+z
    c[2][4]={1,1,1}; //+x+y+z
    c[2][5]={1,1,0}; //+x+y-z
    c[2][6]={0,1,0}; //-x+y-z
    c[2][7]={0,1,1}; //-x+y+z
}
