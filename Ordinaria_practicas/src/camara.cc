#include "camara.h"

Camara :: Camara (const Tupla3f _eye, const Tupla3f _at, const Tupla3f _up,
			const int _tipo, 
			const float _left, const float _right, const float _near, const float _far){

	eye = _eye;
	at  =  _at;
	up  = _up;

	tipo = _tipo;

	left  = _left; 
	right = _right;
	near  = _near;
	far   = _far;
}

void Camara :: zoom ( float factor ){
	left   *= factor;
    right  *= factor;
    top    *= factor;
    bottom *= factor;
}


/*Esta función posiciona al observador de forma que el ojo está en la posición eye, 
mirando hacia el punto at,
con el sentido “hacia arriba” definido por el vector up.*/
void Camara :: setObserver (){
	gluLookAt(	eye(0), eye(1), eye(2),
	    		at(0) , at(1) , at(2),
				up(0) , up(1) , up(2) );	
}

void Camara :: setProyeccion (){
	if (tipo == 0){
		glOrtho(left, right, bottom, top, near, far);	//Ortogonal
	}

	if (tipo == 1){
		glFrustum(left, right, bottom, top, near, far);	//Perspectiva
	}
}

void Camara :: setVentana(float l, float r, float t, float b){
	left 	= l;
	right 	= r;
	top 	= t;
	bottom 	= b;
}

//El modo examinar consiste en mantener fijo el at (hacia qué estamos mirando) y mover el eye(posicion de la cámara) a su alredor
void Camara::rotarXExaminar(const float angle){
    //Colocamos el eye en el centro para que no le afecte la rotación
    eye = eye - at;

    //Aplicamos la rotación y escalamos
    float modulo = sqrt(eye.lengthSq());

    eye[1] = cos(angle) * eye[1] - sin(angle) * eye[2];
    eye[2] = sin(angle) * eye[1] + cos(angle) * eye[2];

    eye = eye.normalized() * modulo;

    //Volvemos a dejar eye como estaba
    eye = eye + at;
}

void Camara::rotarYExaminar(const float angle){

   //Colocamos el eye en el centro para que no le afecte la rotación
    eye = eye - at;

    //Aplicamos la rotación y escalamos
    float modulo = sqrt(eye.lengthSq());

    eye[0] = cos(angle)  * eye[0] - sin(angle) * eye[2];
    eye[2] = -sin(angle) * eye[0] + cos(angle) * eye[2];

    eye = eye.normalized() * modulo;

    //Volvemos a dejar eye como estaba
    eye = eye + at;
}

void Camara::rotarZExaminar(const float angle){

	//Colocamos el eye en el centro para que no le afecte la rotación
	eye = eye - at;

    //Aplicamos la rotación y escalamos
    float modulo = sqrt(eye.lengthSq());

    eye[0] = cos(angle) * eye[0] - sin(angle) * eye[1];
    eye[1] = sin(angle) * eye[0] + cos(angle) * eye[1];

    eye = eye.normalized() * modulo;

    //Volvemos a dejar eye como estaba
    eye = eye + at;
}

//El modo primera persona consiste en mantener fijo el eye (dónde estamos) y mover el at(posicion a la que miramos)
void Camara::rotarXFirstPerson(const float angle){
    //Colocamos el eye en el centro para que no le afecte la rotación
    at = at - eye ;

    //Aplicamos la rotación y escalamos
    float modulo = sqrt(at.lengthSq());

    at[1] = cos(angle) * at[1] - sin(angle) * at[2];
    at[2] = sin(angle) * at[1] + cos(angle) * at[2];

    at = at.normalized() * modulo;

    //Volvemos a dejar at como estaba
    at = at + eye ;
}

void Camara::rotarYFirstPerson(const float angle){
	//Colocamos el eye en el centro para que no le afecte la rotación
    at = at - eye ;

    //Aplicamos la rotación y escalamos
    float modulo = sqrt(at.lengthSq());

    at[0] = cos(angle)  * at[0] + sin(angle) * at[2];
    at[2] = -sin(angle) * at[0] + cos(angle) * at[2];

    at = at.normalized() * modulo;

    //Volvemos a dejar at como estaba
    at = at + eye ;
}

void Camara::rotarZFirstPerson(const float angle){
    //Colocamos el eye en el centro para que no le afecte la rotación
    at = at - eye ;

    //Aplicamos la rotación y escalamos
    float modulo = sqrt(at.lengthSq());

    at[0] = cos(angle) * at[0] - sin(angle) * at[1];
    at[1] = sin(angle) * at[0] + cos(angle) * at[1];

    at = at.normalized() * modulo;

    //Volvemos a dejar at como estaba
    at = at + eye ;
}


void Camara :: mover ( float x , float y , float z ){
	//Se mueve tanto el eye como el at, a la vez
	at  = {at(0) +x, 	at(1) +y, 	at(2) +z};
	eye = {eye(0)+x, 	eye(1)+y, 	eye(2)+z};
}

void Camara :: girar ( float x , float y){
    rotarXFirstPerson(-y * DEG_TO_RAD);
	rotarYFirstPerson(-x * DEG_TO_RAD);
}

void Camara :: girarEx ( float x , float y){
	rotarXExaminar(y * DEG_TO_RAD);
	rotarYExaminar(x * DEG_TO_RAD);
}

Seleccionables Camara :: getSeleccionado(){
    return seleccionado;
}
    
void Camara :: setSeleccionado(Seleccionables obj){
    seleccionado = obj;
}