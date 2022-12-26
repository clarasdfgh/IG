

#include "auxiliar.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************

Escena::Escena()
{
    Front_plane       = 50.0;
    Back_plane        = 2000.0;
    Observer_distance = 4*Front_plane;
    Observer_angle_x  = 0.0 ;
    Observer_angle_y  = 0.0 ;

    ejes.changeAxisSize( 5000 );

   // crear los objetos de la escena....
   cubo = new Cubo(500);
   piramide = new PiramidePentagonal(100, 50);
   modelo = new ObjPLY("plys/ant.ply");
   
      std::vector<Tupla3f> lista ;
      lista.clear();
      //PRUEBAS P2: descomentar para perfil descendente o ascendente
      lista.push_back({0,3,0}); lista.push_back({1,2,0}); lista.push_back({1,1,0}); lista.push_back({0,0,0});
      //lista.push_back({0,0,0}); lista.push_back({1,1,0}); lista.push_back({1,2,0}); lista.push_back({0,3,0});
      
   peon_blanco = new ObjRevolucion("plys/peon.ply", 10);
   peon_negro = new ObjRevolucion("plys/peon.ply", 10);
   rev_lista = new ObjRevolucion(lista, 10);
   cilindro = new Cilindro(10, 3, 1);
   cono = new Cono(10, 3, 1);
   esfera = new Esfera(20, 20, 3, 1);

   //EXAMEN EJERCICIO 2 Y 3
   flecha = new Flecha(20, 20.0, 30.0);
   ejes_flechas = new EjesFlechas();

   //P3: luces
   const Tupla2f orientacion = {0.0,0.0};
   const Tupla3f pos_dir = {0.0,10.0,0.0};
   const Tupla3f pos_pos = {0.0,0.0,0.0};

   luz_pos  = new LuzPosicional (pos_pos, GL_LIGHT0, {1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 0});
   luz_dir  = new LuzDireccional ( orientacion, pos_dir, GL_LIGHT1, {1, 1, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 1});


   //FUENTE MATERIALES: http://www.it.hiof.no/~borres/j3d/explain/light/p-materials.html

   oro = new Material(
      {0.75164f, 0.60648f, 0.22648f, 1.0f }, 
      {0.628281f, 0.555802f, 0.366065f, 1.0f }, 
      { 0.24725f, 0.1995f, 0.0745f, 1.0f }, 
      51.2f
   );

   perla = new Material(
      {1.0f, 0.829f, 0.829f, 0.922f },
      {0.296648f, 0.296648f, 0.296648f, 0.922f },
      { 0.25f, 0.20725f, 0.20725f, 0.922f },
      11.264f
   );

   goma = new Material(
      {0.4f,0.5f,0.5f,1.0f },
      {0.04f,0.7f,0.7f,1.0f },
      { 0.0f,0.05f,0.05f,1.0f },
      10.0f
   );

   blanco_difuso = new Material(
      { 0.5f,0.5f,0.5f,1.0f},
      { 0.0f,0.0f,0.0f,1.0f},
      { 0.05f,0.05f,0.05f,1.0f },
      10.0f
   );

   negro_especular = new Material(
      { 0.0f, 0.0f, 0.0f, 1.0f},
      { 0.9f, 0.9f, 0.9f, 1.0f },
      { 0.02f, 0.02f, 0.02f, 1.0f },
      10.0f
   );

   cubo->setMaterial(*oro);
   piramide->setMaterial(*perla);
   modelo->setMaterial(*goma);
   peon_blanco->setMaterial(*blanco_difuso);
   peon_negro->setMaterial(*negro_especular);
   rev_lista->setMaterial(*perla);
   cilindro->setMaterial(*goma);
   cono->setMaterial(*oro);
   esfera->setMaterial(*perla);

}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer
   glEnable( GL_CULL_FACE );
   glEnable( GL_NORMALIZE );

   glShadeModel(GL_SMOOTH);

	Width  = UI_window_width/10;
	Height = UI_window_height/10;

   change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );
}



// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************

void Escena::dibujar()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();


   if(modo_ilum){
      glEnable(GL_LIGHTING);
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

      if(luz_dir->isActiva()){
         luz_dir->activar();
      }else{
         luz_dir->desactivar();
      }
      if(luz_pos->isActiva()){
         luz_pos->activar();
      }else{
         luz_pos->desactivar();
      }

      //EXAMEN EJERCICIO 3
      ejes_flechas->draw();

   } else{
      glDisable(GL_LIGHTING); //para que los ejes se vean con color puro
      ejes.draw();
   }

   glLineWidth(2);
   glPointSize(5);

   glPushMatrix (); 
   glTranslatef ( 0, -600, 0 );

      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         cubo->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         cubo->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         cubo->draw(2);
      }

   glPopMatrix (); 
   
   glPushMatrix (); 
   glTranslatef ( -100, 0, 100 );

      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         piramide->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         piramide->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         piramide->draw(2);
      }

   glPopMatrix (); 

   glPushMatrix (); 
   glScalef(10,10,10);
   glTranslatef ( -100, 0, -100 );

      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         modelo->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         modelo->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         modelo->draw(2);
      }

   glPopMatrix ();

   glPushMatrix (); 
   glScalef(50,50,50);
   glTranslatef ( 0, 0, -10 );


      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         rev_lista->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         rev_lista->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         rev_lista->draw(2);
      }

   glPopMatrix (); 

   glPushMatrix (); 
   glScalef(40,40,40);
   glTranslatef ( 1, 0, -1 );
   


      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         peon_blanco->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         peon_blanco->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         peon_blanco->draw(2);
      }

   glPopMatrix (); 

   glPushMatrix (); 
   glScalef(40,40,40);
   glTranslatef ( -1, 0, 1 );

      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         peon_negro->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         peon_negro->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         peon_negro->draw(2);
      }

   glPopMatrix (); 

   glPushMatrix (); 
   glScalef(20,20,20);
   glTranslatef ( 5, 0, 5 );


      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         cilindro->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         cilindro->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         cilindro->draw(2);
      }

   glPopMatrix (); 

   glPushMatrix (); 
   glScalef(50,50,50);
   glTranslatef ( -5, 0, -5 );


      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         cono->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         cono->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         cono->draw(2);
      }

   glPopMatrix (); 

   glPushMatrix (); 
   glScalef(50,50,50);
   glTranslatef ( -2, 0, -2 );


      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         esfera->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         esfera->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         esfera->draw(2);
      }

   glPopMatrix ();

   glPushMatrix (); 
      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         flecha->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         flecha->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         flecha->draw(2);
      }

   glPopMatrix ();

}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada( unsigned char tecla, int x, int y )
{
   using namespace std ;
   cout << "Tecla pulsada: '" << tecla << "'" << endl;
   bool salir=false;
   switch( toupper(tecla) )
   {
      case 'Q' :
         if (modoMenu==SELVISUALIZACION || modoMenu==SELLUZ){
            cout << endl << "MENÚ PRINCIPAL" << endl;
            cout << "\tPulse V para modo visualización" << endl;
            cout << "\tPulse Q para salir" << endl;
            modoMenu=NADA;            
         } else if(modoMenu==ALPHA || modoMenu==BETA){
            cout << "\tPulse A para modificar alfa" << endl;
            cout << "\tPulse B para modificar beta" << endl;
            modoMenu=SELLUZ;
         }else {
            salir=true ;
         }
         
         break ;
      
      case 'V' :
         cout << "Iniciado modo selección visualización:" << endl;
         cout << "\tPulse D para puntos" << endl;
         cout << "\tPulse L para líneas" << endl;
         cout << "\tPulse S para sólido" << endl;
         cout << "\tPulse T para iluminación" <<  endl;
         cout << "\tPulse Q para salir" << endl;
         modoMenu=SELVISUALIZACION;
         break ;

      case 'D':
         // MODO PUNTOS
         if (modoMenu==SELVISUALIZACION){
            cout << "Viendo en modo puntos" << endl;
            glDisable(GL_LIGHTING);
            modo_ilum = false;
            modo_punto = !modo_punto;
         } else{
            cout << "Para cambiar modo puntos, active antes el modo selección de visualización (V)" << endl;
         }
         break;
      
      
      case 'L':
         // MODO LÍNEAS
         if (modoMenu==SELVISUALIZACION){
            cout << "Viendo en modo líneas" << endl;
            modo_ilum = false;
            glDisable(GL_LIGHTING);
            modo_linea = !modo_linea;
         } else{
            cout << "Para cambiar modo líneas, active antes el modo selección de visualización (V)" << endl;
         }
         break;

         
      case 'S':
         // MODO SÓLIDO
         if (modoMenu==SELVISUALIZACION){
            cout << "Viendo en modo sólido" << endl;
            modo_ilum = false;
            glDisable(GL_LIGHTING);
            modo_solido = !modo_solido;
         } else{
            cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V)" << endl;
         }
         
         break;

      case 'T':
         // MODO ILUMINACIÓN
         if (modoMenu==SELVISUALIZACION){
            cout << "Iniciado modo iluminación:" << endl;
            cout << "\tPulse 0 para luz direccional" << endl;
            cout << "\tPulse 1 para luz posicional" << endl;
         
            glEnable(GL_LIGHTING);

            modo_punto = false;
            modo_linea = false;
            modo_solido = true;
            modo_ilum = true;

            modoMenu=SELLUZ;

         } else{
            cout << "Para cambiar a modo de iluminación, active antes el modo selección de visualización (V)" << endl;
         }
         break;

      case '0':
         if (modoMenu==SELLUZ){
            if(luz_dir->isActiva()){
               cout << "Desactivada luz direccional" << endl;
               luz_dir->desactivar();
               glDisable(GL_LIGHTING);
               
            } else{
               cout << "Iniciada luz direccional" << endl;
               luz_dir->activar();
            } 
            cout << "\tPulse A para modificar alfa" << endl;
            cout << "\tPulse B para modificar beta" << endl;

         } else{
            cout << "Para acceder a luz direccional, pulse V > T > 0" << endl;
         }
      break;

      case '1':
         if (modoMenu==SELLUZ){
            if(luz_pos->isActiva()){
               cout << "Desactivada luz posicional" << endl;
               luz_pos->desactivar();
               glDisable(GL_LIGHTING);
            } else{
               cout << "Iniciada luz posicional" << endl;
               luz_pos->activar();
            }

         } else{
            cout << "Para acceder a luz posicional, pulse V > T > 1" << endl;
         }
      break;

      case 'A':
         if (modoMenu==SELLUZ){
            cout << "Modificando: alpha" << endl;
            modoMenu = ALPHA;
         } else{
            cout << "Para acceder a alpha, pulse V > T > 0 > A" << endl;
         }
      break;

      case 'B':
         if (modoMenu==SELLUZ){
            cout << "Modificando: beta" << endl;
            modoMenu = BETA;
         } else{
            cout << "Para acceder a luz posicional, pulse V > T > 0 > B" << endl;
         }
      break;

      case '<':
         if (modoMenu==ALPHA){
            cout << "Decrementando: alfa" << endl;
            luz_dir->variarAnguloAlpha( -1.5 );
         } else if (modoMenu==BETA){
            cout << "Decrementando: beta" << endl;
            luz_dir->variarAnguloBeta( -1.5 );
         } else{
            cout << "No ha seleccionado ángulo" << endl;
         }
      break;

      case '>':
         if (modoMenu==ALPHA){
            cout << "Incrementando: alfa" << endl;
            luz_dir->variarAnguloAlpha( 1.5 );
         } else if (modoMenu==BETA){
            cout << "Incrementando: beta" << endl;
            luz_dir->variarAnguloBeta( 1.5 );
         } else{
            cout << "No ha seleccionado ángulo" << endl;
         }
      break;
            
   }
   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         Observer_angle_y-- ;
         break;
	   case GLUT_KEY_RIGHT:
         Observer_angle_y++ ;
         break;
	   case GLUT_KEY_UP:
         Observer_angle_x-- ;
         break;
	   case GLUT_KEY_DOWN:
         Observer_angle_x++ ;
         break;
	   case GLUT_KEY_PAGE_UP:
         Observer_distance *=1.2 ;
         break;
	   case GLUT_KEY_PAGE_DOWN:
         Observer_distance /= 1.2 ;
         break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( const float ratio_xy )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   const float wx = float(Height)*ratio_xy ;
   glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
   change_projection( float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef( 0.0, 0.0, -Observer_distance );
   glRotatef( Observer_angle_y, 0.0 ,1.0, 0.0 );
   glRotatef( Observer_angle_x, 1.0, 0.0, 0.0 );
}
