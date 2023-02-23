#include "_articulacion.h"

Articulacion :: Articulacion(float _r, float _h){
    h = _h;
    r = _r;
    cil = new Cilindro(4, 30, h, r);
    esf = new Esfera(30, 30, r, r);
    angulo = 0;
}

void Articulacion :: rotar(float incr){
    angulo += incr;
}

void Articulacion :: draw(int c){
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPushMatrix (); 
        esf->draw(c);
    glPopMatrix (); 

    glPushMatrix (); 
        glRotatef (angulo,1,0,0);
        glTranslatef (0,-(h+r),0);

        cil->draw(c);
    glPopMatrix (); 
}