#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"

#include "cubo.h"
#include "piramidepentagonal.h"
#include "objply.h"
#include "objrevolucion.h"
#include "cilindro.h"
#include "cono.h"
#include "esfera.h"

#include "_monigote.h"

#include "material.h"
#include "luzdireccional.h"
#include "luzposicional.h"
#include "camara.h"

typedef enum {NADA, SELVISUALIZACION, SELLUZ, ALPHA, BETA, ANIMACION, ANIMACIONMAN, CAMARA} menu;
typedef enum {PRIMERAPERSONA, EXAMINAR, NINGUNO} estRaton;
class Escena
{

   private:
    // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)
       
    // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;

   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;

    // Transformación de cámara
	void change_projection();
	void change_observer();
    

   void clear_window();

   menu modoMenu=NADA;
   // Objetos de la escena
   Ejes ejes;
   
   Cubo * cubo = nullptr ; // es importante inicializarlo a 'nullptr'
   PiramidePentagonal * piramide= nullptr ;
   ObjPLY * modelo = nullptr ; 
   ObjRevolucion * peon_blanco = nullptr;
   ObjRevolucion * peon_negro = nullptr;
   ObjRevolucion * rev_lista = nullptr;
   Cilindro * cilindro = nullptr;
   Cono * cono = nullptr;
   Esfera * esfera = nullptr;


   LuzDireccional * luz_dir = nullptr;
   LuzPosicional * luz_pos = nullptr;

   Material * oro = nullptr;
   Material * perla = nullptr;
   Material * goma = nullptr;

   Material * blanco_difuso = nullptr;
   Material * negro_especular = nullptr;

   Camara * camaras[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
   int camara_actual = 0;


   estRaton estadoRaton = NINGUNO;
   int xant = 0;
   int yant = 0;

   Monigote * monigote = nullptr;
   int elementomodelo = 0;
   float incr = 0.0;
   float a_bola = 0;
   float a_posbola = 0;

   //Fases animación automática. Explicadas con detalle en su función.
   bool fase1 = 1;
   bool fase2 = 0;
   bool fase3 = 0;
   bool fase4 = 0;
   bool finciclo = 0;
   bool rebote   = 0;


   bool modo_punto  = 1;
   bool modo_linea  = 1;
   bool modo_solido = 1;
   bool modo_ilum[2] = {0,0};

   
   public:

    Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;

	// Dibujar y P6
	void dibujar() ;
    void dibujarSeleccion();
    void getColorPixel(int x, int y);

	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );

    // P4: Animación
    void animarAutomatico();
    void cambiarVelocidad(float m);

    int getElemModelo();
    void setElemModelo(int e);
    void incrElemModelo(int incr);

    //P6: Interacción del ratón con la cámara
    void clickRaton(int boton, int estado, int x, int y);
    void ratonMovido(int x, int y);

};
#endif
