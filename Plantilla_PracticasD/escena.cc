

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
    // .......completar: ...
    // .....

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

	Width  = UI_window_width/10;
	Height = UI_window_height/10;

   change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );

   std::vector<Tupla3f> lista ;
   lista.clear();

   //PRUEBAS: descomentar para descendente o ascendente
   lista.push_back({0,3,0}); lista.push_back({1,2,0}); lista.push_back({1,1,0}); lista.push_back({0,0,0});
   //lista.push_back({0,0,0}); lista.push_back({1,1,0}); lista.push_back({1,2,0}); lista.push_back({0,3,0});

   cubo = new Cubo(50);
   piramide = new PiramidePentagonal(100, 50);

   modelo = new ObjPLY("plys/ant.ply");

   rev_ply = new ObjRevolucion("plys/peon.ply", 10);
   rev_lista = new ObjRevolucion(lista, 10);

   cilindro = new Cilindro(10, 3, 1);
   cono = new Cono(10, 3, 1);

   esfera = new Esfera(20, 20, 3, 1);
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
   ejes.draw();

    // COMPLETAR
    //   Dibujar los diferentes elementos de la escena
    // Habrá que tener en esta primera práctica una variable que indique qué objeto se ha de visualizar
    // y hacer 
    // cubo->draw()
    // o    piramide->draw()

   glLineWidth(2);
   glPointSize(5);



   glPushMatrix (); 
   glTranslatef ( 100, 0, 100 );

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
   glScalef(50,50,50);
   glTranslatef ( 10, 0, -10 );


      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         rev_ply->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         rev_ply->draw(1);
      }

      if (modo_solido){
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         rev_ply->draw(2);
      }

   glPopMatrix (); 

   glPushMatrix (); 
   glScalef(50,50,50);
   glTranslatef ( 10, 0, -5 );


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
         if (modoMenu!=NADA){
            cout << endl << "MENÚ PRINCIPAL" << endl;
            cout << "\tPulse O para modo selección de objetos" << endl;
            cout << "\tPulse V para modo visualización" << endl;
            cout << "\tPulse Q para salir" << endl;
            modoMenu=NADA;            
         } else {
            salir=true ;
         }
         break ;
      
      case 'O' :
         cout << "Iniciado modo selección de objeto" << endl;
         cout << "\tPulse C para cubo" << endl;
         cout << "\tPulse P para pirámide" << endl;
         cout << "\tPulse M para modelo" << endl;
         cout << "\tPulse Q para salir" << endl;
         modoMenu=SELOBJETO; 
         break ;
      
      case 'V' :
         cout << "Iniciado modo selección visualización:" << endl;
         cout << "\tPulse D para puntos" << endl;
         cout << "\tPulse L para líneas" << endl;
         cout << "\tPulse S para sólido" << endl;
         cout << "\tPulse Q para salir" << endl;
         modoMenu=SELVISUALIZACION;
         break ;

      case 'D':
         // MODO PUNTOS
         if (modoMenu==SELVISUALIZACION){
            cout << "Viendo en modo puntos" << endl;
            modo_punto = !modo_punto;
         } else{
            cout << "Para cambiar modo puntos, active antes el modo selección de visualización (V)" << endl;
         }
         break;
      
      
      case 'L':
         // MODO LÍNEAS
         if (modoMenu==SELVISUALIZACION){
            cout << "Viendo en modo líneas" << endl;
            modo_linea = !modo_linea;
         } else{
            cout << "Para cambiar modo líneas, active antes el modo selección de visualización (V)" << endl;
         }
         break;

         
      case 'S':
         // MODO SÓLIDO
         if (modoMenu==SELVISUALIZACION){
            cout << "Viendo en modo sólido" << endl;
            modo_solido = !modo_solido;
         } else{
            cout << "Para cambiar modo sólido, active antes el modo selección de visualización (V)" << endl;
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
