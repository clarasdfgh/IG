#include "esfera.h"


Esfera :: Esfera (  const int m , const int n , 
                        const float h , const float r ){
    radio = r;
    std::vector<Tupla3f> perfil ;

    const float PI = 2*acos(0.0);
    float x, y, alfa;

    for(int i=0; i < m; i++){
        alfa = (i * 2 * PI) / m;

        x = -r * cos(alfa);
        y = -r * sin(alfa);

        perfil.push_back( Tupla3f(x, y, 0) );
    }

    crearMalla(perfil, n);                
    setColor();
}