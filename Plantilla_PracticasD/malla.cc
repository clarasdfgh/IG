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
   // P1: (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // Creamos los VBO de los vértices, caras y colores
   setColor();

   if(id_vbo_v == 0){
      id_vbo_v = crearVBO(GL_ARRAY_BUFFER, v.size()*3* sizeof(float), v.data());
   }

   if(id_vbo_f == 0){
      id_vbo_f = crearVBO(GL_ELEMENT_ARRAY_BUFFER, f.size()*3* sizeof(int), f.data());
   }
   
   for(GLuint i=0; i<=color; i++){
      if(id_vbo_c[i] == 0){
         id_vbo_c[i] = crearVBO(GL_ARRAY_BUFFER, c[color].size()*3* sizeof(float), c[color].data());
      }
   }


   for(GLuint i=0; i<=color; i++){
      if(id_vbo_c[i] != 0){
         glEnableClientState( GL_COLOR_ARRAY );    //habilitar uso de array de colores
         glBindBuffer(GL_ARRAY_BUFFER, id_vbo_c[i]);  //especificar VBO
         glColorPointer(3, GL_FLOAT, 0, 0);        //usar el buffer activo para color 
      }
   }
   

   glEnableClientState(GL_VERTEX_ARRAY); // Habilitar tabla de vértices


   // activar buffer VBO de vértices
   glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_v ); 
   
   // usar como buffer de vertices el actualmente activo 
   glVertexPointer ( 3 , GL_FLOAT , 0 , 0 ); 

   // desactivar buffer: VBO de vértices. 
   glBindBuffer ( GL_ARRAY_BUFFER , 0 ); 
   
   // habilitar el uso de tabla de vértices 
   glEnableClientState( GL_VERTEX_ARRAY ); 
   
   // activar buffer: VBO de triángulos 
   glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , id_vbo_f ); 

   // dibujar con el buffer de índices activo 
   glDrawElements ( GL_TRIANGLES , 3* f.size () , GL_UNSIGNED_INT , 0 ); 

   // desactivar buffer: VBO de triángulos 
   glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , 0 ); 

   // desactivar uso de array de vértices 
   glDisableClientState( GL_VERTEX_ARRAY );
}

void Malla3D::setColor(){
   c[0].resize(v.size());
   c[1].resize(v.size());
   c[2].resize(v.size());

   /*Tupla3f dots  = new Tupla3f(0.590, 0.0118, 0.195);
   Tupla3f lines = new Tupla3f(0.0887, 0.0306, 0.170);
   Tupla3f fill  = new Tupla3f(0.584, 0.510, 0.630);
   */

   for(int i=0; i<c[0].size(); i++){
      c[0] = std::vector<Tupla3f>(v.size(), Tupla3f(0.590, 0.0118, 0.195));
      c[1] = std::vector<Tupla3f>(v.size(), Tupla3f(0.0887, 0.0306, 0.170));
      c[2] = std::vector<Tupla3f>(v.size(), Tupla3f(0.584, 0.510, 0.630));
   }

}

void Malla3D::setNormales(){
   int p, q, r;
   Tupla3f a, b;
   Tupla3f perpendicular, m;

   for(int i=0; i<f.size(); i++){
      p=f[i](0);
      q=f[i](1);
      r=f[i](2);

      a = q-p;
      b = r-p;

      perpendicular = a.cross(b);
      m = perpendicular.normalized();

      nv.push_back(m);
   }

}