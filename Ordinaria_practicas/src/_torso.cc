#include "_torso.h"

Torso :: Torso(float _r, float _h){
    h = _h;
    r = _r;
    torso = new Cilindro(4, 30, h, r);
    cabeza = new Esfera(30, 30, r*0.75, r*0.75);

    //EXAMEN EJ4: gorro flotante
    gorro = new PiramidePentagonal(10,7);

    angulo = 0;
}

void Torso :: rotar(float incr){
    angulo += incr;
}

void Torso :: draw(int c){
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPushMatrix ();
        glTranslatef (0,(h+r)+20,0);
        glRotatef(a_gorro, 0,1,0);
        gorro->draw(c);
    glPopMatrix (); 

    
    glPushMatrix ();
        glTranslatef (0,(h+r),0);
        cabeza->draw(c);
    glPopMatrix (); 

    glPushMatrix (); 
        torso->draw(c);
    glPopMatrix (); 
}
