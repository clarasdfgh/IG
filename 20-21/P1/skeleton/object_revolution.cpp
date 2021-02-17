#include "object_revolution.h"

object_revolution::object_revolution(const vector<_vertex3f> &profile, const int iterations, \
                                     const bool top_lid, const bool bottom_lid, \
                                     const axis eje)
{
    this->profile = profile;
    this->iterations = iterations;

    this->top_lid = top_lid;
    this->bottom_lid = bottom_lid;

    this->eje = eje;

    make_object(/*profile,*/ eje);
}

void object_revolution::make_object(/*const vector<_vertex3f> &profile, */const axis eje)
{
    float angle;

    //Vertices
    for(int i = 0; i < iterations; i++){
        angle = (M_PI * 2 * i) / iterations;

        for(unsigned j = 0; j < profile.size() - 1; j++){
            _vertex3f v;

            //Case x,y,z con formulas de la teoría
            switch(eje){
                case X_AXIS:
                    v.x = profile[j]._0;
                    v.y = profile[j]._1 * cos(angle) - profile[j]._2 * sin(angle);
                    v.z = profile[j]._1 * sin(angle) + profile[j]._2 * cos(angle);
                break;

                case Y_AXIS:
                    v.x =  profile[j]._0 * cos(angle) + profile[j]._2 * sin(angle);
                    v.y =  profile[j]._1;
                    v.z = -profile[j]._0 * sin(angle) + profile[j]._2 * cos(angle);

                break;

                case Z_AXIS:
                    v.x = profile[j]._0 * cos(angle) - profile[j]._1 * sin(angle);
                    v.y = profile[j]._0 * sin(angle) + profile[j]._2 * cos(angle);
                    v.z =profile[j]._2;

                break;
            }
        }
    }

    //Caras
    unsigned v1 = 0;
    unsigned v2 = 0;
    unsigned v3 = 0;

    for (int i = 0; i < iterations; i++){
        for (unsigned j = 0; j < profile.size() - 1; j++){
            v1 = profile.size() * i + j;
            v2 = profile.size() * (i+1) + j;
            v3 = v2 + 1;

            Triangles.push_back({v1, v2, v3});

            v2 += 1;
            v3 = v1 + 1;


            Triangles.push_back({v1, v2, v3});
         }
      }

    //Tapas
    if(top_lid || bottom_lid){
        if(top_lid){
            _vertex3ui triangulo(0, Vertices.size()-1, 0);

            for(int i = 0; i < iterations; i++){
                triangulo._2 = profile.size() * (i + 1) - 1;
                triangulo._0 = profile.size() + triangulo._2;

                Triangles.push_back(triangulo);
            }
        }

        if(bottom_lid){
            _vertex3ui triangulo(0, Vertices.size()-2, 0);

            for(int i = 0; i < iterations; i++){
                triangulo._0 = profile.size() * i;
                triangulo._2 = (triangulo._0 + profile.size()) % triangulo._1;

                Triangles.push_back(triangulo);
            }

        }
    }

}
