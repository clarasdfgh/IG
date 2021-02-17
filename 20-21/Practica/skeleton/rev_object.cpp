#include "rev_object.h"

/*****************************************************************************/
rev_object::rev_object(const vector<_vertex3f> &profile, const int iterations, const axis eje){
    this->profile    = profile;
    this->iterations = iterations;
    this->eje        = eje;
}

/*****************************************************************************/
void rev_object::make_object(const vector<_vertex3f> &profile,const axis eje){
    make_vertex(profile,eje);
    make_faces(profile);
    make_lids(profile);
}

/*****************************************************************************/
void rev_object::make_vertex(const vector<_vertex3f> &profile,const axis eje){
    float angle;

    for(int i = 0; i < iterations; i++){
        angle = (M_PI * 2 * i) / iterations;
        for(unsigned int j = 0; j < profile.size() - 1; j++){
            _vertex3f v;

            //Case eje, con formulas de la teoría
            switch(eje){
                case X_AXIS:
                    v.x = profile[j]._0;
                    v.y = profile[j]._1 * cos(angle) + profile[j]._2 * -sin(angle);
                    v.z = profile[j]._1 * sin(angle) + profile[j]._2 * cos(angle);
                break;

                case Y_AXIS:
                    v.x =  profile[j]._0 * cos(angle) + profile[j]._2 * sin(angle);
                    v.y =  profile[j]._1;
                    v.z =  profile[j]._0 * -sin(angle) + profile[j]._2 * cos(angle);

                break;

                case Z_AXIS:
                    v.x = profile[j]._0 * cos(angle) - profile[j]._1 * sin(angle);
                    v.y = profile[j]._0 * sin(angle) + profile[j]._1 * cos(angle);
                    v.z = profile[j]._2;

                break;
            }
            Vertices.push_back(v);
        }
    }
    std::cout << "Haciendo vertices\n";
}

/*****************************************************************************/
void rev_object::make_faces(const vector<_vertex3f> &profile){
    unsigned int v1 = 0;
    unsigned int v2 = 0;
    unsigned int v3 = 0;


    for (int i = 0; i < iterations; i++){
        for (unsigned int j = 0; j < profile.size() - 1; j++){
            v1 = profile.size() * i + j;
            v2 = profile.size() * (i+1) + j;
            v3 = v2 + 1;

            Triangles.push_back({v1, v2, v3});

            v2 += 1;
            v3 = v1 + 1;

            Triangles.push_back({v1, v2, v3});
        }
    }
    std::cout << "Haciendo caras\n";
}

/*****************************************************************************/
void rev_object::make_lids(const vector<_vertex3f> &profile){
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
    std::cout << "Haciendo tapas\n";
}
