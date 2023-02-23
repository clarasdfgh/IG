#ifndef LUZ_POS_INCLUDED
#define LUZ_POS_INCLUDED

#include "auxiliar.h"
#include "luz.h"

class LuzPosicional : public Luz { 
public: 
    LuzPosicional ( const Tupla3f & p, GLenum id_, Tupla4f camb, Tupla4f cdif, Tupla4f cesp );
};

#endif
