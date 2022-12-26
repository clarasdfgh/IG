#include "auxiliar.h"
#include "objrevolucion.h"


// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias) {
   // completar ......(práctica 2)
   ply::read_vertices(archivo, v_perfil);
   crearMalla(v_perfil, num_instancias);
   setColor();
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias) {
   v_perfil = archivo;
   crearMalla(v_perfil, num_instancias);
}

void ObjRevolucion::setPolos(std::vector<Tupla3f> perfil, float x_ini, float x_fin){
   hay_polo_norte = abs(0.0 - x_fin) < 1e-7;
   hay_polo_sur   = abs(0.0 - x_ini) < 1e-7;

   if(hay_polo_norte){
      polo_norte = perfil.back();
   }
   if(hay_polo_sur){
      polo_sur = Tupla3f(perfil.front());
   }

}


void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
   float y_ini = perfil_original.front()(Y);
   float y_fin = perfil_original.back()(Y);

   ascendente = ( y_ini < y_fin);

   std::vector<Tupla3f> perfil;

   if(!ascendente){
      for(int i=perfil_original.size(); i>=0; i--){
         perfil.push_back(perfil_original[i]);
      }
   }else {
      perfil = perfil_original;
   }

   float x_ini = perfil.front()(X);
   float x_fin = perfil.back()(X);
   setPolos(perfil, x_ini, x_fin);

   if(hay_polo_norte){
      perfil.pop_back();
   }
   if(hay_polo_sur){
      perfil.erase(perfil.begin());
   }

   const float PI = 2*acos(0.0);
   int n = num_instancias;
   int m = perfil.size();

   float x, z, alfa;

   v.clear();

   for(int i=0; i<n; i++){
      alfa = (i * 2 * PI) / n;

      for(int j=0; j<m; j++){
         x = perfil[j](X) * cos(alfa) + perfil[j](Z) * sin(alfa);
         z = perfil[j](Z) * cos(alfa) - perfil[j](X) * sin(alfa);

         v.push_back( Tupla3f(x, perfil[j](Y), z) );
      } 
   }

   int a, b;
   f.clear();

   for (int i=0; i<n; i++) {
      for(int j=0; j<m-1; j++) {
         a = m*i + j;
         b = m * ((i + 1) % n) + j;

         f.push_back({a, b, b+1});
         f.push_back({a, b+1, a+1});
      }
   }

   int f1, f2, f3;

   if (hay_polo_sur){
      v.push_back(polo_sur);

      for(int i=0; i<n-1; i++) {
         f1 = perfil.size()*i;
         f2 = v.size() - 1;
         f3 = f1 + perfil.size();

         f.push_back({f1,f2,f3});
      }
      f1 = perfil.size() * (n - 1);

      f.push_back({f1, f2, 0});
   }

   if (hay_polo_norte){
      v.push_back(polo_norte);

      for(int i=0; i<n-1; i++) {
         f1 = perfil.size() * (i + 1) - 1 ;;
         f2 = v.size() - 1;
         f3 = f1 + perfil.size();

         f.push_back({f3,f2,f1});
      }
      f1 = perfil.size() * n - 1;
      f3 = perfil.size() - 1;

      f.push_back({f3,f2,f1});
   }
   
}
