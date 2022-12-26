#include "ejesflechas.h"

//EXAMEN EJERCICIO 3
EjesFlechas::EjesFlechas()
{
    fx = new Flecha(20, 5.0, 70.0);
    fy = new Flecha(20, 5.0, 70.0);
    fz = new Flecha(20, 5.0, 70.0);

    rojo = new Material(
      { 0.5f,0.0f,0.0f,1.0f}, 
      {0.7f,0.6f,0.6f,1.0f }, 
      { 0.0f,0.0f,0.0f,1.0f },
      320.0f
    );

    verde = new Material(
      { 0.1f,0.35f,0.1f,1.0f}, 
      {0.45f,0.55f,0.45f,1.0f }, 
      { 0.0f,0.0f,0.0f,1.0f },
      320.0f
    );

    azul = new Material(
      { 0.0f,0.20980392f,0.70980392f,1.0f}, 
      {0.50196078f,0.20196078f,0.70196078f,1.0f }, 
      { 0.0f,0.1f,0.06f ,1.0f}, 
      320.0f
    );


    fx->setMaterial(*rojo);
    fy->setMaterial(*verde);
    fz->setMaterial(*azul);

}

void EjesFlechas::draw()
{

    glPushMatrix (); 

        glPushMatrix (); 
            glRotatef(-90, 0,0,1);
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            fx->draw(2);
        glPopMatrix ();

        glPushMatrix (); 
            //glRotatef(0, 0,1,0);
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            fy->draw(2);
        glPopMatrix ();

        glPushMatrix (); 
            glRotatef(90, 1,0,0);
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            fz->draw(2);
        glPopMatrix ();

   glPopMatrix ();
}
