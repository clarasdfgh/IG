#include "luz.h"

void Luz::activar(){
    activa = true;
    glEnable(GL_LIGHTING);
    glEnable(id);

    glLightfv(id, GL_DIFFUSE, colorDifuso );
    glLightfv(id, GL_AMBIENT, colorAmbiente );
    glLightfv(id, GL_SPECULAR, colorEspecular );
    
    glLightfv(id, GL_POSITION, posicion);

    
}

void Luz::desactivar(){
    activa = false;
    glDisable(GL_LIGHTING);
    glDisable(id);    
}

bool Luz::isActiva(){
    return activa;
}


