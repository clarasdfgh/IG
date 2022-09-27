

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

   cubo = new Cubo(50);
   piramide = new PiramidePentagonal(100, 50);
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

   glLineWidth(0.5);
   glPointSize(5);


   if (modo_punto){
      glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

      if(objeto_vista == 0)
         cubo->draw();
      else if(objeto_vista == 1)
         piramide->draw();

  }

  if (modo_linea){
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

      if(objeto_vista == 0)
         cubo->draw();
      else if(objeto_vista == 1)
         piramide->draw();
  }

  if (modo_solido) {
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

      if(objeto_vista == 0)
         cubo->draw();
      else if(objeto_vista == 1)
         piramide->draw();
  }
    
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

      // P1: COMPLETAR con los diferentes opciones de teclado
      case 'C':
         // VER CUBO
         if (modoMenu==SELOBJETO){
            cout << "Viendo cubo" << endl;
            objeto_vista = 0;
         }else{
            cout << "Para visualizar el cubo, active antes el modo selección de objeto (O)" << endl;
         }
         break;

      case 'P':
         // VER PIRÁMIDE
         if (modoMenu==SELOBJETO){
            cout << "Viendo pirámide" << endl;
            objeto_vista = 1;
         }else{
            cout << "Para visualizar la pirámide, active antes el modo selección de objeto (O)" << endl;
         }
         break;

      case 'D':
         // MODO PUNTOS
         cout << "Viendo en modo puntos" << endl;
         modo_punto = modo_punto == false? true : false;
         break;
      
      
      case 'L':
         // MODO LÍNEAS
         cout << "Viendo en modo líneas" << endl;
         modo_linea = modo_linea == false? true : false;
         break;

         
      case 'S':
         // MODO SÓLIDO
          cout << "Viendo en modo sólido" << endl;
         modo_solido = modo_solido == false? true : false;
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
