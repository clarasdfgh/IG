#ifndef LUZ_INCLUDED
#define LUZ_INCLUDED

#include "auxiliar.h"

class Luz {
public:
    Tupla4f posicion;
    GLenum id;
    Tupla4f colorAmbiente;
    Tupla4f colorDifuso;
    Tupla4f colorEspecular;
    bool activa = false;

    void activar();
    void desactivar();
    bool isActiva();
};

#endif
