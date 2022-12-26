#include "flecha.h"

//EXAMEN EJERCICIO 2
Flecha :: Flecha (  const int n_rev, const int h_punta, const float h_cuerpo){
    
    altura_punta = h_punta;
    altura_cuerpo = h_cuerpo;
    float r_punta = h_punta;
    float r_cuerpo = r_punta/2;

    std::vector<Tupla3f> perfil ;

    perfil.push_back({0,0,0}); 
    perfil.push_back({r_cuerpo,0,0}); 
    perfil.push_back({r_cuerpo,h_cuerpo,0}); 
    perfil.push_back({r_punta,h_cuerpo,0});
    perfil.push_back({0,h_punta+h_cuerpo,0});

    crearMalla(perfil, n_rev);                
    setColor();
}