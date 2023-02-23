

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

   /**************************************************************************/
   //Inicialización de los objetos de la escena
   /**************************************************************************/
   std::vector<Tupla3f> lista ;
      lista.clear();
      lista.push_back({0,0,0}); 
      lista.push_back({1,0,0}); 
      lista.push_back({1,2,0}); 
      lista.push_back({0.5,2.5,0});
      lista.push_back({0.35,4,0});
      lista.push_back({0,4,0});
   
   modelo = new ObjPLY("plys/ant.ply");   
   peon_blanco = new ObjRevolucion("plys/peon.ply", 10);
   peon_negro = new ObjRevolucion("plys/peon.ply", 10);
   rev_lista = new ObjRevolucion(lista, 10);

   cubo = new Cubo(500);
   piramide = new PiramidePentagonal(100, 50);
   cilindro = new Cilindro(4, 10, 3, 1);
   cono = new Cono(3, 10, 3, 1);
   esfera = new Esfera(20, 20, 3, 1);

   monigote = new Monigote();
   elementomodelo = 0;
   incr = 0.8;


   /**************************************************************************/
   //Inicialización de luces, materiales y cámaras
   /**************************************************************************/
   //P3: luces
   const Tupla2f orientacion = {0.0,0.0};
   const Tupla3f pos_dir = {0.0,10.0,0.0};
   const Tupla3f pos_pos = {0.0,0.0,0.0};

   luz_pos  = new LuzPosicional (pos_pos, GL_LIGHT0, {1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 0});
   luz_dir  = new LuzDireccional ( orientacion, GL_LIGHT1, {1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 0});

   //P3: materiales
   //FUENTE MATERIALES: http://www.it.hiof.no/~borres/j3d/explain/light/p-materials.html

   oro = new Material(
      { 0.75164f, 0.60648f, 0.22648f, 1.0f }, 
      { 0.628281f, 0.555802f, 0.366065f, 1.0f }, 
      { 0.24725f, 0.1995f, 0.0745f, 1.0f }, 
      51.2f
   );

   perla = new Material(
      { 1.0f, 0.829f, 0.829f, 0.922f },
      { 0.296648f, 0.296648f, 0.296648f, 0.922f },
      { 0.25f, 0.20725f, 0.20725f, 0.922f },
      11.264f
   );

   goma = new Material(
      { 0.4f,0.5f,0.5f,1.0f },
      { 0.04f,0.7f,0.7f,1.0f },
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


   //P6: Cámaras
   float near = 100.0;
   float far = 2000.0;
   float left  = -1.0;        //Ponemos aquí valores arbitrarios porque luego se modificarán según el tamaño de la ventana
   float right = 1.0;
   Tupla3f up = {0, 1, 0};
   
   //Cámara 1 - isométrica. Perspectiva.
   Tupla3f eye = {0, 300, 500};
	Tupla3f at = {0, 0, 0};

   camaras[0] = new Camara(eye, at, up, 1, left, right, near, far);

   //Cámara 2 - cenital. Perspectiva.
   eye = {0,  500, 100};
   at  = {0,  0,   99};
   up  = {0, -1,   0};
   camaras[1] = new Camara(eye, at, up, 1, left, right, near, far);

   //Cámara 3 - isométrica. Ortogonal.
   eye = {700, 200, 700};
   at  = {0, 0, 0};
   up = {0, 1, 0};
   camaras[2] = new Camara(eye, at, up, 0, left, right, near, far);

   //Cámara 4 - isométrica. Perspectiva. Como la 1, pero desde el otro lado
   eye = {-500, 200, -300};
	at = {0, 0, 0};

   camaras[3] = new Camara(eye, at, up, 1, left, right, near, far);

   //EXAMEN EJ6: cambiamos una de las cámaras extra (sin perder funcionalidad) por la camara que nos solicitan.
   eye = {1000, 1000, 1000};
	at = {0, 150, 0};
   near = 10.0;
   far = 5000.0;

   camaras[4] = new Camara(eye, at, up, 0, left, right, near, far);
            camaras[4]->zoom(0.01);
            camaras[4]->zoom(0.01);
            camaras[4]->zoom(0.01);
            change_projection();
            change_observer();

   camara_actual = 0;
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

   //P6: Cámaras, definición de left, right, top, bottom
   for (int i = 0; i < 5; i++){

		camaras[i]->setVentana(  -UI_window_width/10, 
                              UI_window_width/10, 
                              UI_window_height/10, 
                              -UI_window_height/10);
	
	}

   change_projection();
   change_observer();
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

   glDisable(GL_LIGHTING); //para que los ejes se vean con color puro
   glDisable(GL_LIGHT0);
   glDisable(GL_LIGHT1);

   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	change_observer();
 
   glLineWidth(3);
   glPointSize(5);

   ejes.draw();

   if(modo_ilum[0]||modo_ilum[1]){
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
   }

   glPushMatrix ();
   //glRotatef(-90,0,1,0);

   //monigote
   glPushMatrix (); 
   glScalef(1.7,1.7,1.7);
      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         monigote->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         monigote->draw(1);
      }

      if (modo_solido){
         if(camaras[camara_actual]->getSeleccionado() == MONIGOTE){
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            monigote->draw(4);
         } else{
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            monigote->draw(2);
         }
        
      }

   glPopMatrix ();

   //mesa
   glPushMatrix (); 
      glTranslatef ( 0, 40, 250 );
      glScalef(0.3,0.1,0.45);
      //glScalef(0.3,0.3,0.3);
      
      if (modo_punto){
         glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
         cubo->draw(0);
      }

      if (modo_linea){
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         cubo->draw(1);
      }

      if (modo_solido){
         if(camaras[camara_actual]->getSeleccionado() == MESA){
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            cubo->draw(4);
         } else{
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            cubo->draw(2);
         }
        
      }
      
      

   glPopMatrix (); 
   
   //piramide
   glPushMatrix (); 
      glTranslatef ( -55, 96, 350 );
      glScalef(0.1,0.1,0.1);

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

   //hormiga
   glPushMatrix (); 
      glTranslatef ( 60, 100, 170 );
      glRotatef(-45, 0, 1, 0);
      glScalef(0.5,0.5,0.5);

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

   //botella
   glPushMatrix (); 
      glTranslatef ( 60, 96, 280 );
      glScalef(5,5,5);  

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

   //peon blanco
   glPushMatrix (); 
      glTranslatef ( 65, 100, 290 );
      glScalef(3,3,3); 

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

   //peon negro
   glPushMatrix (); 
      glTranslatef ( 60, 96, 300 );
      glRotatef (-50, 0,1,0);
      glRotatef (90, 0,0,1);
      glScalef(3,3,3); 

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

   //cilindro
   glPushMatrix (); 
      glTranslatef ( -55, 96, 340 );
      glScalef(4.5,4.5,4.5);

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

   //cono
   glPushMatrix (); 
      glTranslatef ( -45, 96, 348 );
      glScalef(4.5,4.5,4.5);

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

   //esfera
   glPushMatrix (); 
      glTranslatef ( 0, 0, a_posbola );
      glTranslatef ( -40, 100, 248 );
      glRotatef    ( a_bola, 1,0,0);
      glScalef(4,4,4);

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
   glPopMatrix ();

}

void Escena::dibujarSeleccion(){
   glDisable ( GL_DITHER ); // deshabilita el degradado 


   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();

   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   
   //A cada objeto seleccionable hay que hacerle exactamente las mismas transformaciones que le haríamos en el dibujar normal,
   //si no, no va a coincidir el click con lo que estamos viendo en pantalla

   glPushMatrix (); 
    glRotatef(-90,0,1,0);

   
      glPushMatrix (); 
         //glColor3f (1.0 ,0 ,0); 
         glScalef(1.7,1.7,1.7);
         
         monigote->draw(3);
      glPopMatrix();
      

      glPushMatrix (); 
         //glColor3f (0 ,1.0 ,0);
         glTranslatef ( 0, 70, 250 );
         glScalef(0.3,0.05,0.45);
         
         cubo->draw(3);
      glPopMatrix(); 

      /*glPushMatrix (); 
         //glColor3f (0 ,0 ,1.0); 
         glTranslatef ( 60, 96, 280 );
         glScalef(5,5,5);  
        
         rev_lista->draw(3);
      glPopMatrix(); */

   glPopMatrix (); 
 
   
   glEnable ( GL_DITHER );
}

void Escena::getColorPixel(int x, int y){
   glDisable ( GL_DITHER ); // deshabilita el degradado 
   glDisable ( GL_LIGHTING ); 
   glDisable ( GL_TEXTURE );

   GLint viewport[4];
   GLfloat coordenada[3];
   Tupla3f pos;

   Tupla3f at_inicial = camaras[camara_actual]->at;

   glGetIntegerv(GL_VIEWPORT, viewport);
   glReadPixels(x, viewport[3]-y, 1, 1, GL_RGB, GL_FLOAT, (void *) coordenada);

   Tupla3f pixel = {coordenada[0], coordenada[1], coordenada[2]};



   std::cout << pixel[0] << " " << pixel[1] << " " << pixel[2] << std::endl;

   if (pixel[0] == 0 && pixel[1] == 1 && pixel[2] == 0){
		pos = {-250, 70, 0 };
      camaras[camara_actual]->setAt(pos);
		camaras[camara_actual]->setSeleccionado(MESA);

      std::cout << "Selección: MESA" << std::endl;
   }

   else if (pixel[0] == 0 && pixel[1] == 0 && pixel[2] == 0){
      pos = {0, 70, 0};
		camaras[camara_actual]->setAt(pos);
		camaras[camara_actual]->setSeleccionado(MONIGOTE);

      std::cout << "Selección: MONIGOTE" << std::endl;
   }

   else{
      std::cout << "No ha seleccionado nada" << std::endl;
      camaras[camara_actual]->setAt(at_inicial);
		camaras[camara_actual]->setSeleccionado(ESCENA);
   }



   glEnable ( GL_DITHER );
   glEnable ( GL_LIGHTING ); 
   glEnable ( GL_TEXTURE );
}

int Escena::getElemModelo(){
   return elementomodelo;
} 

void Escena::setElemModelo(int e){
    elementomodelo = e;
} 

void Escena::incrElemModelo(int incr){
   elementomodelo += incr;
   elementomodelo = elementomodelo%9;
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

   Tupla3f eye_orig;
   Tupla3f at_orig;

   switch( toupper(tecla) )
   {
      case 'Q' :
         if (modoMenu==SELVISUALIZACION || modoMenu==SELLUZ || 
             modoMenu == ANIMACIONMAN || modoMenu == ANIMACION || modoMenu == CAMARA ){
            cout << endl << "MENÚ PRINCIPAL" << endl;
            cout << "\tPulse V para modo visualización" << endl;
            cout << "\tPulse M para animación manual" << endl;
            cout << "\tPulse A para animación automática" << endl;
            cout << "\tPulse C para modo cámaras" << endl;
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
            luz_dir->desactivar();
            luz_pos->desactivar();
            modo_ilum[0] = 0;
            modo_ilum[1] = 0;
            modo_punto = !modo_punto;
         } else{
            cout << "Para cambiar modo puntos, active antes el modo selección de visualización (V)" << endl;
         }
         break;
      
      
      case 'L':
         // MODO LÍNEAS
         if (modoMenu==SELVISUALIZACION){
            cout << "Viendo en modo líneas" << endl;
            luz_dir->desactivar();
            luz_pos->desactivar();
            modo_ilum[0] = 0;
            modo_ilum[1] = 0;
            modo_linea = !modo_linea;
         } else{
            cout << "Para cambiar modo líneas, active antes el modo selección de visualización (V)" << endl;
         }
         break;

         
      case 'S':
         // MODO SÓLIDO
         if (modoMenu==SELVISUALIZACION){
            cout << "Viendo en modo sólido" << endl;
            luz_dir->desactivar();
            luz_pos->desactivar();
            modo_ilum[0] = 0;
            modo_ilum[1] = 0;
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
         
            modo_punto  = 0;
            modo_linea  = 0;
            modo_solido = 1;

            modoMenu=SELLUZ;

         } else{
            cout << "Para cambiar a modo de iluminación, active antes el modo selección de visualización (V)" << endl;
         }
         break;

      case '0':
         if (modoMenu==SELLUZ){
            if(luz_dir->isActiva()){
               cout << "Desactivada luz direccional" << endl;
               modo_ilum[0] = 0;
               luz_dir->desactivar();
               
            } else{
               cout << "Iniciada luz direccional" << endl;
               modo_ilum[0] = 1;
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
               modo_ilum[1] = 0;
               luz_pos->desactivar();
            } else{
               cout << "Iniciada luz posicional" << endl;
               modo_ilum[1] = 1;
               luz_pos->activar();
            }

         } else if(modoMenu==CAMARA){
            cout << "Cambiando a cámara 1..." << endl;
            camara_actual = 0;
            change_projection();
            change_observer();
         } else{
            cout << "Operación inválida: acceda a un submenú que proporcione esta opción" << endl;
         }
      break;

      case '2':
         if (modoMenu==CAMARA){
            cout << "Cambiando a cámara 2..." << endl;
            camara_actual = 1;
            change_projection();
            change_observer();
         } else{
            cout << "Operación inválida: acceda a un submenú que proporcione esta opción" << endl;
         }
      break;

      case '3':
         if (modoMenu==CAMARA){
            cout << "Cambiando a cámara 3..." << endl;
            camara_actual = 2;
            change_projection();
            change_observer();
         } else{
            cout << "Operación inválida: acceda a un submenú que proporcione esta opción" << endl;
         }
      break;

      case '4':
         if (modoMenu==CAMARA){
            cout << "Cambiando a cámara 4..." << endl;
            camara_actual = 3;
            change_projection();
            change_observer();
         } else{
            cout << "Operación inválida: acceda a un submenú que proporcione esta opción" << endl;
         }
      break;

      case '5':
         if (modoMenu==CAMARA){
            cout << "Cambiando a cámara 5..." << endl;
            camara_actual = 4;
            change_projection();
            change_observer();
         } else{
            cout << "Operación inválida: acceda a un submenú que proporcione esta opción" << endl;
         }
      break;


      case 'A':
         if(modoMenu == NADA){
            cout << "Iniciado modo animación automática:" << endl;
            monigote->restaurarPos();
            modoMenu=ANIMACION;
         } else if(modoMenu == SELVISUALIZACION || modoMenu == SELLUZ){
            cout << "Modificando: alpha" << endl;
            modoMenu = ALPHA;
         }
         
      break;

      case 'B':
         cout << "Modificando: beta" << endl;
         modoMenu = BETA;
       
      break;

      case '<':
         if (modoMenu==ALPHA){
            cout << "Decrementando: alfa" << endl;
            luz_dir->variarAnguloAlpha( -1 );
         } else if (modoMenu==BETA){
            cout << "Decrementando: beta" << endl;
            luz_dir->variarAnguloBeta( -1 );
         } else{
            cout << "No ha seleccionado ángulo" << endl;
         }
      break;

      case '>':
         if (modoMenu==ALPHA){
            cout << "Incrementando: alfa" << endl;
            luz_dir->variarAnguloAlpha( 1 );
         } else if (modoMenu==BETA){
            cout << "Incrementando: beta" << endl;
            luz_dir->variarAnguloBeta( 1 );
         } else{
            cout << "No ha seleccionado ángulo" << endl;
         }
      break;

      case '+':
         if (modoMenu==ANIMACIONMAN){

            switch (getElemModelo()){
               case 0:
                  cout << "\t\tElemento seleccionado actual: torso" << endl;
                  monigote->modTorso(10);
               break;
            
               case 1:
                  cout << "\t\tElemento seleccionado actual: muslo izdo" << endl;
                  monigote->modMusloIzdo(10);
               break;

               case 2:
                  cout << "\t\tElemento seleccionado actual: gemelo izdo" << endl;
                  monigote->modGemeloIzdo(10);
               break;

               case 3:
                  cout << "\t\tElemento seleccionado actual: muslo dcho" << endl;
                  monigote->modMusloDcho(10);
               break;

               case 4:
                  cout << "\t\tElemento seleccionado actual: gemelo dcho" << endl;
                  monigote->modGemeloDcho(10);
               break;

               case 5:
                  cout << "\t\tElemento seleccionado actual: hombro izdo" << endl;
                  monigote->modHombroIzdo(10);
               break;

               case 6:
                  cout << "\t\tElemento seleccionado actual: codo izdo" << endl;
                  monigote->modCodoIzdo(10);
               break;

               case 7:
                  cout << "\t\tElemento seleccionado actual: hombro dcho" << endl;
                  monigote->modHombroDcho(10);
               break;

               case 8:
                  cout << "\t\tElemento seleccionado actual: codo dcho" << endl;
                  monigote->modCodoDcho(10);
               break;
            }
         } else if (modoMenu = ANIMACION){
            cout << "Aumentando velocidad de animación..." << endl;
            incr += 0.2;
         }
      break;

      case '-':
          if (modoMenu==ANIMACIONMAN){

            switch (getElemModelo()){
               case 0:
                  cout << "\t\tElemento seleccionado actual: torso" << endl;
                  monigote->modTorso(-10);
               break;
            
               case 1:
                  cout << "\t\tElemento seleccionado actual: muslo izdo" << endl;
                  monigote->modMusloIzdo(-10);
               break;

               case 2:
                  cout << "\t\tElemento seleccionado actual: gemelo izdo" << endl;
                  monigote->modGemeloIzdo(-10);
               break;

               case 3:
                  cout << "\t\tElemento seleccionado actual: muslo dcho" << endl;
                  monigote->modMusloDcho(-10);
               break;

               case 4:
                  cout << "\t\tElemento seleccionado actual: gemelo dcho" << endl;
                  monigote->modGemeloDcho(-10);
               break;

               case 5:
                  cout << "\t\tElemento seleccionado actual: hombro izdo" << endl;
                  monigote->modHombroIzdo(-10);
               break;

               case 6:
                  cout << "\t\tElemento seleccionado actual: codo izdo" << endl;
                  monigote->modCodoIzdo(-10);
               break;

               case 7:
                  cout << "\t\tElemento seleccionado actual: hombro dcho" << endl;
                  monigote->modHombroDcho(-10);
               break;

               case 8:
                  cout << "\t\tElemento seleccionado actual: codo dcho" << endl;
                  monigote->modCodoDcho(-10);
               break;
         }
      } else if (modoMenu = ANIMACION){
            cout << "Disminuyendo velocidad de animación..." << endl;
            incr -= 0.2;

         }
      break;

      case 'C':
         cout << "Iniciado modo selección de cámaras:" << endl;
         cout << "\tPulse 1, 2 o 3 para cambiar de cámara" << endl;
         cout << "\tPulse G para restaurar las cámaras a sus posiciones originales" << endl;
         cout << "\tPulse Q para salir" << endl;
         modoMenu=CAMARA;
      break;

      case 'G':
         cout << "\tCámaras restauradas" << endl;
        
            //Cámara 1
            eye_orig = {-600, 300, 200};
            at_orig = {0, 0, 0};

            camaras[0]->at  = at_orig;
            camaras[0]->eye = eye_orig;

            //Cámara 2
            eye_orig  = {0,  500, 100};
            at_orig  = {0,  0,   99};

            camaras[1]->at  = at_orig;
            camaras[1]->eye = eye_orig ;

            //Cámara 3
            eye_orig  = {700, 200, 700};
            at_orig  = {0, 0, 0};

            camaras[2]->at  = at_orig;
            camaras[2]->eye = eye_orig ;

            //Cámara 4
            eye_orig  = {-500, 200, -300};
            at_orig = {0, 0, 0};

            camaras[3]->at  = at_orig;
            camaras[3]->eye = eye_orig ;

            //Cámara 5
            eye_orig  = {-500, 0, 300};
            at_orig = {0, 0, 0};

            camaras[4]->at  = at_orig;
            camaras[4]->eye = eye_orig ;

         modoMenu=CAMARA;
      break;

      case 'M':
         cout << "Iniciado modo animación manual:" << endl;
         cout << "\tPulse N para iterar por los distintos elementos del modelo" << endl;
         cout << "\tPulse + o - para mover el elemento seleccionado" << endl;
         cout << "\tPulse W o S respectivamente para mover el modelo hacia adelante/atrás" << endl;
         cout << "\tPulse Q para salir" << endl;

         cout << "\t\tElemento seleccionado actual: torso" << endl;

         setElemModelo(0);

         modoMenu=ANIMACIONMAN;
      break;

      case 'N':
            if(modoMenu = ANIMACIONMAN){
               incrElemModelo(1);
            cout << "Elemento seleccionado modificado: " << getElemModelo() << endl;
            } else{
               cout << "Opción inválida, acceda a un menú que permita esta opción";
            }
      break;
            
   }
   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   /*Cambiamos la funcionalidad para las nuevas cámaras.
   
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
	}*/

   switch ( Tecla1 )
   {  
      //F1 a F4 - rotación de la cámara
      case GLUT_KEY_F1:
         camaras[camara_actual]->rotarYFirstPerson(0.1);
         break;
	   case GLUT_KEY_F2:
         camaras[camara_actual]->rotarYFirstPerson(-0.1);
         break;
	   case GLUT_KEY_F3:
         camaras[camara_actual]->rotarXFirstPerson(0.1);
         break;
	   case GLUT_KEY_F4:
         camaras[camara_actual]->rotarXFirstPerson(-0.1);
         break;

      //F10, F11 - movimiento arriba/abajo de la cámara
      case GLUT_KEY_F10:
         camaras[camara_actual]->mover(0,1,0);
         break;
	   case GLUT_KEY_F11:
         camaras[camara_actual]->mover(0,-1,0);
         break;
   
      //Teclas de dirección - movimiento primera persona sobre el plano (X, Z)
      case GLUT_KEY_LEFT:
         camaras[camara_actual]->mover(-1,0,0);
         break;
	   case GLUT_KEY_RIGHT:
         camaras[camara_actual]->mover(1,0,0);
         break;
	   case GLUT_KEY_UP:
         camaras[camara_actual]->mover(0,0,-1);
         break;
	   case GLUT_KEY_DOWN:
         camaras[camara_actual]->mover(0,0,1);
         break;

      //Avpag, repag - zoom
	    case GLUT_KEY_PAGE_UP:
         camaras[camara_actual]->zoom(1.5);
         change_projection();
         break;
	   case GLUT_KEY_PAGE_DOWN:
         camaras[camara_actual]->zoom(0.5);
         change_projection();
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

void Escena::change_projection()
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   
   //P6: Ahora esto lo hacemos en setProyeccion de la Cámara, porque puede ser ortogonal.
   //const float wx = float(Height)*ratio_xy ;
   //glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );
   
   camaras[camara_actual]->setProyeccion();
}

//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
   change_projection(  );
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
   
   //P6: Todo esto ya no nos hace falta, lo hacemos con los parámetros de la cámara
   //glTranslatef( 0.0, 0.0, -Observer_distance );
   //glRotatef( Observer_angle_y, 0.0 ,1.0, 0.0 );
   //glRotatef( Observer_angle_x, 1.0, 0.0, 0.0 );

   camaras[camara_actual]->setObserver();
}

//**************************************************************************
// Funcion para la interacción del ratón con la cámara
//***************************************************************************

void Escena::clickRaton(int boton, int estado, int x, int y) {
   xant = x;
   yant = y;

   if(boton == GLUT_RIGHT_BUTTON){
      if(estado == GLUT_DOWN){
         if(camaras[camara_actual]->getSeleccionado() == ESCENA){
             estadoRaton = PRIMERAPERSONA;
         } else {
            estadoRaton = EXAMINAR;
         }
      } else {
         estadoRaton = NINGUNO;
      }
   } else if (boton == 3){ //Rueda ratón hacia arriba
      camaras[camara_actual]->zoom(1.5);
      change_projection();

   } else if (boton == 4){ //Rueda ratón hacia abajo
		camaras[camara_actual]->zoom(0.5);
      change_projection();

   } else if (boton == GLUT_LEFT_BUTTON){
      if (estado == GLUT_UP){
			dibujarSeleccion();
			getColorPixel(x,y);
		}
   }
}

void Escena::ratonMovido(int x, int y) {
   if(estadoRaton == PRIMERAPERSONA){
      camaras[camara_actual]->girar(x-xant, y-yant);
      xant = x;
      yant = y;
   } else if(estadoRaton == EXAMINAR){
      camaras[camara_actual]->girarEx(x-xant, y-yant);
      xant = x;
      yant = y;
   }
}

//**************************************************************************
// Función para la animación automática de la escena
//***************************************************************************

void Escena::animarAutomatico() {
   if (modoMenu == ANIMACION){
   //Las fases fueron declaradas en escena.h para que no se actualicen constantemente con la función idle. Estas son:
   //Fase 1: el monigote se inclina hacia delante, flexionando las piernas y avanzando hacia la mesa.
   //Fase 2: el monigote echa hacia atrás el brazo con el palo
   //Fase 3: el palo se pone en posición horizontal, y el monigote estira el brazo con el palo e impacta con la bola
   //Fase 4: la bola rueda para luego volver a su posición.

   //Cuando la fase se completa (las partes implicadas en el movimiento alcanzan cierta posición), pasamos a la siguiente.
   //Cuando no quedan fases, se resetea el monigote y vuelve a empezar desde el principio.
      
      //EXAMEN EJ4: el gorro gira siempre.
      monigote->torso->a_gorro+=incr*2;

      //EXAMEN EJ6: animación de la cámara
      
      camaras[4]->rotarYExaminar(/*camaras[4]->eye[Y] +*/ 0.1);
      //camaras[4]->girarEx ( incr, 0);
      //camaras[4]->rotarYFirstPerson(incr);

      if(fase1){
         if(monigote->a_torso<30){
            monigote->modTorso(incr);
         }

         if(monigote->a_pos<50){
            monigote->modPos(incr);
         }
         
         if(monigote->a_musloizdo>-50){
            monigote->modMusloIzdo(-incr);
            monigote->modGemeloIzdo(incr);
            monigote->modMusloDcho(0.5*incr);
            monigote->modGemeloDcho(0.5*incr);
         }
         
         if(monigote->a_torso>=30 && monigote->a_pos>=50 && monigote->a_musloizdo<=-50){
            std::cout << "FIN FASE 1" << std::endl; 
            fase1=0;
            fase2=1;
         }
      }
      
      if (fase2){
         if(monigote->a_hombrodcho<60){
            monigote->modHombroDcho(incr);
         }

         if(monigote->a_cododcho>-90){
            monigote->modCodoDcho(-incr);
         }
         
         if(monigote->a_hombrodcho>=60 && monigote->a_cododcho<=-90){
            std::cout << "FIN FASE 2" << std::endl; 
            fase2 = 0;
            fase3 = 1;
         }

         
      } 
      
      if (fase3){
         if(monigote->a_hombrodcho>-90){
            monigote->modHombroDcho(-10*incr);
            monigote->modCodoDcho(4*incr);
            monigote->modPalo(6*incr);
         }         
         
         if(monigote->a_hombrodcho<=-90){
            std::cout << "FIN FASE 3" << std::endl; 
            fase3 = 0;
            fase4 = 1;
         }
         
      }
      
      if (fase4){
         if(a_posbola < 90 && !finciclo && !rebote){
            a_bola = 0.3;
            a_posbola += 2*incr;

            if(a_posbola > 90){
               rebote = 1;
            }

         } else if (rebote && !finciclo){
            rebote = 1;
            a_bola = -0.3;
            a_posbola -= incr;

            if(a_posbola < 0){
               finciclo = 1;
            }
         }

         if(finciclo){
            std::cout << "FIN FASE 4" << std::endl; 
            fase4 = 0;
         }

      }
      
      if(!fase1 && !fase2 && !fase3 && !fase4){
         std::cout << "REESTABLECIENDO" << std::endl; 
         monigote->restaurarPos();
         a_bola    = 0;
         a_posbola = 0;

         fase1 = 1;
         fase2 = 0;
         fase3 = 0;
         fase4 = 0;

         finciclo = 0;
         rebote   = 0;
      }
   }
}
