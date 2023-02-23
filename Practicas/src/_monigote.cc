#include "_monigote.h"

Monigote :: Monigote(){
    musloizdo  = new Articulacion(r_pierna, h_pierna);
    muslodcho  = new Articulacion(r_pierna, h_pierna);;
    gemeloizdo = new Articulacion(r_pierna, h_pierna);;
    gemelodcho = new Articulacion(r_pierna, h_pierna);

    hombroizdo  = new Articulacion(r_brazo, h_brazo);
    hombrodcho  = new Articulacion(r_brazo, h_brazo);
    codoizdo    = new Articulacion(r_brazo, h_brazo);
    cododcho    = new Articulacion(r_brazo, h_brazo);

    torso      = new Torso(r_torso, h_torso);

    palo       = new Cilindro(4,3,50,2);

    setColorSeleccion(getColorSel());
}

void Monigote :: restaurarPos(){
       a_musloizdo    = 0;
       a_muslodcho    = 0;
       a_gemeloizdo   = 0;
       a_gemelodcho   = 0;
       a_hombroizdo   = 0;
       a_hombrodcho   = 0;
       a_codoizdo     = 0;
       a_cododcho     = 0;
       a_torso        = 0;
      
       a_palo         = 0;
      
       a_pos          = 0;
       a_pospalo      = 0; 
}

void Monigote :: draw(int c){
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPushMatrix ();
        glTranslatef (0,0,a_pos);

        //TREN INFERIOR *****************************************
        glPushMatrix();
            glTranslatef (0,3*r_pierna+2*h_pierna,0);

            //Pierna izda
            glPushMatrix ();
                glTranslatef (r_torso/2,0,0);
                glRotatef(a_musloizdo, 1,0,0);

                musloizdo->draw(c);

                glPushMatrix();
                    glTranslatef (0,(-2*r_pierna)-h_pierna,0);
                    glRotatef(a_gemeloizdo, 1,0,0);
                    gemeloizdo->draw(c);
                glPopMatrix();

            glPopMatrix (); 

            //Pierna dcha
            glPushMatrix ();
                glTranslatef (-r_torso/2,0,0);
                glRotatef(a_muslodcho, 1,0,0);

                muslodcho->draw(c);

                glPushMatrix();
                    glTranslatef (0,(-2*r_pierna)-h_pierna,0);
                    glRotatef(a_gemelodcho, 1,0,0);
                    gemelodcho->draw(c);
                glPopMatrix();

            glPopMatrix (); 

        glPopMatrix();

        //TREN SUPERIOR *****************************************
        glPushMatrix();
            //Para subirlo todo encima de las piernas
            glTranslatef (0,3*r_pierna+2*h_pierna,0);
            glRotatef(a_torso, 1,0,0);

            glPushMatrix ();
                torso->draw(c);
            glPopMatrix (); 
   
            //Brazo izdo
            glPushMatrix ();
                glTranslatef (r_torso+r_brazo, h_torso-r_brazo ,0);
                glRotatef(a_hombroizdo, 1,0,0);

                hombroizdo->draw(c);

                glPushMatrix();
                    glTranslatef (0,-2*r_brazo-h_brazo,0);
                    glRotatef(a_codoizdo, 1,0,0);
                    codoizdo->draw(c);
                glPopMatrix();

            glPopMatrix (); 

            //Brazo dcho
            glPushMatrix ();
                glTranslatef (-r_torso-r_brazo, h_torso-r_brazo ,0);
                glRotatef(a_hombrodcho, 1,0,0);

                hombroizdo->draw(c);

                glPushMatrix();
                    glTranslatef (0,-2*r_brazo-h_brazo,0);
                    glRotatef(a_cododcho, 1,0,0);
                    cododcho->draw(c);

                //Palo de billar
                glPushMatrix();
                    glTranslatef (0,-h_brazo, a_pospalo);
                    glRotatef(a_palo, 1,0,0);
                    glRotatef(90,0,1,0);
                    glRotatef(90,0,0,1);
                    palo->draw(c);

                glPopMatrix();

                glPopMatrix();

            glPopMatrix (); 

        glPopMatrix();
        
    glPopMatrix();
}
