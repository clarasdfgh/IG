#include "auxiliar.h"
#include "malla.h"

// *****************************************************************************
//
// IG_D Clase Malla3D
//
// *****************************************************************************
// -----------------------------------------------------------------------------
GLuint crearVBO(GLuint tipo_vbo, GLuint tam, GLvoid * puntero_ram){
   GLuint id_vbo;

   glGenBuffers(1, & id_vbo);          //crear nuevo VBO, obtener su id
   glBindBuffer(tipo_vbo, id_vbo);     //activar VBO usando su id

   //Transferencia de datos RAM->GPU
   glBufferData(tipo_vbo, tam, puntero_ram, GL_STATIC_DRAW);

   glBindBuffer(tipo_vbo, 0);          //desactivar VBO

   return id_vbo;
}

// Función de visualización de la malla,

void Malla3D::draw()
{
   // P1: (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // Creamos los VBO de los vértices, caras y colores
   if(id_vbo_v == 0){
      id_vbo_v = crearVBO(GL_ARRAY_BUFFER, v.size()*3* sizeof(float), v.data());
   }

   if(id_vbo_f == 0){
      id_vbo_f = crearVBO(GL_ELEMENT_ARRAY_BUFFER, f.size()*3* sizeof(float), f.data());
   }


   if(id_vbo_c != 0){
      glEnableClientState( GL_COLOR_ARRAY );    //habilitar uso de array de colores
      glBindBuffer(GL_ARRAY_BUFFER, id_vbo_c);  //especificar VBO
      glColorPointer(3, GL_FLOAT, 0, 0);        //usar el buffer activo para color 
   } else{
      id_vbo_c = crearVBO(GL_ARRAY_BUFFER, c.size()*3* sizeof(float), c.data());
   }

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
   glDrawElements ( GL_TRIANGLES , 3* f . size () , GL_UNSIGNED_INT , 0 ); 

   // desactivar buffer: VBO de triángulos 
   glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , 0 ); 

   // desactivar uso de array de vértices 
   glDisableClientState( GL_VERTEX_ARRAY ); 
}
