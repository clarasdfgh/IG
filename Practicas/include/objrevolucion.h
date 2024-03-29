// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef OBJREVOLUCION_H_INCLUDED
#define OBJREVOLUCION_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"
#include "ply_reader.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 v y 6 caras)

class ObjRevolucion : public Malla3D
{
public:
    ObjRevolucion();
    ObjRevolucion(const std::string & archivo, int num_instancias);
    ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias) ;

    inline Tupla3f getColorSel(){ return colorsel; };


private:
    std::vector<Tupla3f> v_perfil;

    bool ascendente = true;
    bool hay_polo_norte = false;
    bool hay_polo_sur = false;
    Tupla3f polo_norte;
    Tupla3f polo_sur;
    
    Tupla3f colorsel = {0,0,1.0};

    void setPolos(std::vector<Tupla3f> perfil_original, Tupla2f xz_ini, Tupla2f xz_fin);
    
protected:
    void crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias);

} ;




#endif
