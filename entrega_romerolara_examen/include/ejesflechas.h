#ifndef _EJES_FLECHAS_H
#define _EJES_FLECHAS_H

#include "auxiliar.h"
#include "flecha.h"

//EXAMEN EJERCICIO 3
class EjesFlechas {

private:
	Flecha * fx = nullptr;
    Flecha * fy = nullptr;
    Flecha * fz = nullptr;

    Material * azul = nullptr;
    Material * verde = nullptr;
    Material * rojo = nullptr;


public:
	EjesFlechas();
	void draw();

};
#endif
