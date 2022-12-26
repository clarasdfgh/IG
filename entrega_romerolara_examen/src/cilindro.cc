#include "cilindro.h"


Cilindro :: Cilindro (  /*const int num_vert_perfil ,*/ const int n , 
                        const float h , const float r ){
    altura = h;
    radio = r;

    std::vector<Tupla3f> perfil ;

    perfil.push_back({0,0,0}); 
    perfil.push_back({r,0,0}); 
    perfil.push_back({r,h,0}); 
    perfil.push_back({0,h,0});



    crearMalla(perfil, n);                
    setColor();
}