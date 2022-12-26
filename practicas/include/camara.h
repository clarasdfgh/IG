#ifndef CAMARA_H_INCLUDED
#define CAMARA_H_INCLUDED

#include "auxiliar.h"

class Camara { 
public:
    Tupla3f eye ;  //dónde está la cámara
    Tupla3f at ;   //hacia qué mira la cámara
    Tupla3f up ;   //define hacia donde está arriba en nuestro mundo (normalmente eje Y (0,1,0))
    
    int tipo;                          // Ortogonal 0 o Perspectiva 1 
    float left, right, near , far ;    // o bien aspect, fov, near, far; 
    
    Camara (const Tupla3f eye, const Tupla3f at, const Tupla3f up,
			const int tipo, 
			const float left, const float right, const float near, const float far);

    void zoom ( float factor );
    void setObserver ();
    void setProyeccion (); 

    void rotarXExaminar ( float angle ); 
    void rotarYExaminar ( float angle ); 
    void rotarZExaminar ( float angle ); 

    void rotarXFirstPerson ( float angle ); 
    void rotarYFirstPerson ( float angle ); 
    void rotarZFirstPerson ( float angle ); 

    void mover ( float x , float y , float z );     

}

#endif 