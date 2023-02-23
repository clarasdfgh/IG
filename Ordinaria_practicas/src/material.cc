#include "material.h"

Material::Material ( ){
    difuso = {1.0, 0.0, 0.0, 1.0}; 
    especular = {0.0, 1.0, 0.0, 1.0}; 
    ambiente = {0.0, 0.0, 1.0, 1.0}; 
    brillo = 0.5; 
} 

Material::Material ( Tupla4f mdif , Tupla4f mesp, Tupla4f mamb , float brillo_ ){
    difuso    = mdif;
    especular = mesp;
    ambiente  = mamb;
    brillo    = brillo_;
} 
    
void Material::aplicar(){
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuso);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiente);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brillo);

    glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
    glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}