#include "luzposicional.h"

LuzPosicional::LuzPosicional ( const Tupla3f & p, GLenum id_, Tupla4f camb, Tupla4f cdif, Tupla4f cesp ){
    id = id_;

    colorAmbiente = camb;
    colorDifuso = cdif;
    colorEspecular = cesp;


    posicion = {p(X), p(Y), p(Z), 1};
}
