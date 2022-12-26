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
   m.aplicar();
   setColor();

   if(id_vbo_v == 0) {
      id_vbo_v = crearVBO(GL_ARRAY_BUFFER, v.size() * 3 * sizeof(float), v.data());
   }

   if(id_vbo_f == 0) {
      id_vbo_f = crearVBO(GL_ELEMENT_ARRAY_BUFFER, f.size() * 3 * sizeof(int), f.data());
   }

   for(GLuint i=0; i<=color; i++){
      if(id_vbo_c[i] == 0){
         id_vbo_c[i] = crearVBO(GL_ARRAY_BUFFER, c[color].size()*3* sizeof(float), c[color].data());
      }
   }

   if(id_vbo_nv == 0) {
      setNormales();
      id_vbo_nv = crearVBO(GL_ARRAY_BUFFER, nv.size() * 3 * sizeof(float), nv.data());
   }

   //Activar buffer: VBO de vértices
   glBindBuffer(GL_ARRAY_BUFFER, id_vbo_v);
   //Usar como buffer de vértices el actualmente activo
   glVertexPointer(3, GL_FLOAT, 0, 0);
   //Desactivar buffer: VBO de vértices
   glBindBuffer(GL_ARRAY_BUFFER, 0);

   // Tabla de colores
   for(GLuint i=0; i<=color; i++){
      if(id_vbo_c[i] != 0){
         glEnableClientState( GL_COLOR_ARRAY );       //habilitar uso de array de colores
         glBindBuffer(GL_ARRAY_BUFFER, id_vbo_c[i]);  //especificar VBO
         glColorPointer(3, GL_FLOAT, 0, 0);           //usar el buffer activo para color 
      }
   }

   //Habilitar el uso de la tabla de vértices
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_COLOR_ARRAY);

   //Activar buffer: VBO de triángulos
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_f);
   //Dibujar con el buffer de índices activo
   glDrawElements(GL_TRIANGLES, 3 * f.size(), GL_UNSIGNED_INT, 0);
   //Desactivar buffer: VBO de triángulos
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

   //Desactivar uso de array de vértices
   glDisableClientState(GL_VERTEX_ARRAY);
   glDisableClientState(GL_COLOR_ARRAY);

   if (glIsEnabled(GL_LIGHTING)){
      glEnableClientState(GL_NORMAL_ARRAY);
      glBindBuffer(GL_ARRAY_BUFFER, id_vbo_nv);
      glNormalPointer(GL_FLOAT,0, 0 );
      glBindBuffer(GL_ARRAY_BUFFER, 0);

      //m.aplicar();

   }
}

void Malla3D::setColor(){
   c[0].resize(v.size());
   c[1].resize(v.size());
   c[2].resize(v.size());

   /*Tupla3f dots  = new Tupla3f(0.590, 0.0118, 0.195);
   Tupla3f lines = new Tupla3f(0.0887, 0.0306, 0.170);
   Tupla3f fill  = new Tupla3f(0.584, 0.510, 0.630);
   */

   int j[2] = {0};
   std::cout << c[0].size() << "aaaaaaaaaaaAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

   for(int i=0; i<c[0].size(); i++){
      c[0] = std::vector<Tupla3f>(v.size(), Tupla3f(0.590, 0.0118, 0.195));
      c[1] = std::vector<Tupla3f>(v.size(), Tupla3f(0.0887, 0.0306, 0.170));
      //c[2] = std::vector<Tupla3f>(v.size(), Tupla3f(0.584, 0.510, 0.630));
      
      //EXAMEN EJERCICIO 1
      c[2][i] = Tupla3f(1.0-(i+j[0]%3)/10.0, 1.0-(i+j[1]%3)/10.0, 1.0-(i+j[2]%3)/10.0);

      if(i%3==0){
         j[0] = 1;
         j[1] = 0;
         j[2] = 0;
      }else if(i%3==1){
         j[0] = 0;
         j[1] = 1;
         j[2] = 0;
      }else if(i%3==2){
         j[0] = 0;
         j[1] = 0;
         j[2] = 1;
      }
   }

}

void Malla3D::setNormales(){
   Tupla3f p, q, r;
   Tupla3f a, b;
   Tupla3f perpendicular, m;

   nv.resize(v.size());
   //fill(nv.begin(), nv.end(), {0.0, 0.0, 0.0});
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
