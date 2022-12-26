#include "auxiliar.h"
#include "malla.h"

// *****************************************************************************
//
// IG_D Clase Malla3D
//
// *****************************************************************************
// -----------------------------------------------------------------------------
GLuint Malla3D::crearVBO(GLuint tipo_vbo, GLuint tam, GLvoid * puntero_ram){
   GLuint id_vbo;

   glGenBuffers(1, & id_vbo);          //crear nuevo VBO, obtener su id
   glBindBuffer(tipo_vbo, id_vbo);     //activar VBO usando su id

   //Transferencia de datos RAM->GPU
   glBufferData(tipo_vbo, tam, puntero_ram, GL_STATIC_DRAW);

   glBindBuffer(tipo_vbo, 0);          //desactivar VBO

   return id_vbo;
}

// Función de visualización de la malla,

void Malla3D::draw(int color)
{
   if(id_vbo_v == 0) {
      id_vbo_v = crearVBO(GL_ARRAY_BUFFER, v.size() * 3 * sizeof(float), v.data());
   }

   if(id_vbo_f == 0) {
      id_vbo_f = crearVBO(GL_ELEMENT_ARRAY_BUFFER, f.size() * 3 * sizeof(int), f.data());
   }

   if(id_vbo_nv == 0) {
      setNormales();
      id_vbo_nv = crearVBO(GL_ARRAY_BUFFER, nv.size() * 3 * sizeof(float), nv.data());
   }

   m.aplicar();
   setColor(color);

   //Activar buffer: VBO de vértices
   glBindBuffer(GL_ARRAY_BUFFER, id_vbo_v);
   //Usar como buffer de vértices el actualmente activo
   glVertexPointer(3, GL_FLOAT, 0, 0);
   //Desactivar buffer: VBO de vértices
   glBindBuffer(GL_ARRAY_BUFFER, 0);

   // Tabla de colores
   glEnableClientState( GL_COLOR_ARRAY );       //habilitar uso de array de colores
   glBindBuffer(GL_ARRAY_BUFFER, id_vbo_c[color]);  //especificar VBO
   glColorPointer(3, GL_FLOAT, 0, 0);           //usar el buffer activo para color 
   glBindBuffer(GL_ARRAY_BUFFER, 0);

   if (glIsEnabled(GL_LIGHTING)){
      glEnableClientState(GL_NORMAL_ARRAY);
      glBindBuffer(GL_ARRAY_BUFFER, id_vbo_nv);
      glNormalPointer(GL_FLOAT,0, 0 );
      glBindBuffer(GL_ARRAY_BUFFER, 0);
   }

   //Habilitar el uso de la tabla de vértices
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_NORMAL_ARRAY);

   //Activar buffer: VBO de triángulos
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_f);
   //Dibujar con el buffer de índices activo
   glDrawElements(GL_TRIANGLES, 3 * f.size(), GL_UNSIGNED_INT, 0);   //ESTO ES EL DIBUJAR-- TODO LO Q VAYA DESPUÉS NO SE ESTÁ HACIENDO
   
   //Desactivar buffer: VBO de triángulos
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

   //Desactivar uso de array de vértices
   glDisableClientState(GL_VERTEX_ARRAY);
   glDisableClientState(GL_COLOR_ARRAY);
   glDisableClientState(GL_NORMAL_ARRAY);
}

void Malla3D::setColor(int color){
   for(int i=0; i<v.size();i++){
      c[0].push_back(c_puntos);
      c[1].push_back(c_linea);
      c[2].push_back(c_solido);
   }

   if(id_vbo_c[color] == 0){
      id_vbo_c[color] = crearVBO(GL_ARRAY_BUFFER, c[color].size()*3*sizeof(float), c[color].data());
   }
     
}

void Malla3D::setNormales(){
   Tupla3f p, q, r;
   Tupla3f a, b;
   Tupla3f perpendicular, m;

   nv.resize(v.size());
   
   for(int i=0; i<nv.size();i++){
      nv[i] = {0.0, 0.0, 0.0};
   }

   for(int i=0; i<f.size(); i++){
      p = v[f[i](X)];
      q = v[f[i](Y)];
      r = v[f[i](Z)];

      a = q-p;
      b = r-p;

      perpendicular = a.cross(b);
      //m = perpendicular.normalized();

      nv[f[i](X)] = perpendicular  + nv[f[i](X)];
      nv[f[i](Y)] = perpendicular  + nv[f[i](Y)];
      nv[f[i](Z)] = perpendicular  + nv[f[i](Z)];
   }

   for(int i=0; i<nv.size();i++){
      nv[i] = nv[i].normalized();
   }

}

void Malla3D::setMaterial(Material material){
   m = material;
}
