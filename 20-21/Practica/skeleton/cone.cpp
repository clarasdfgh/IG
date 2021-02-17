#include "cone.h"

_cone::_cone(const int iterations,\
          const float height, const float radius, const axis eje){

    switch(eje){
            case X_AXIS:
                profile.push_back({0,0,0});
                profile.push_back({0,radius,0});
                profile.push_back({height,0,0});
            break;

            case Y_AXIS:
                profile.push_back({0,0,0});
                profile.push_back({radius,0,0});
                profile.push_back({0,height,0});
            break;

            case Z_AXIS:
                profile.push_back({0,0,0});
                profile.push_back({0,radius,0});
                profile.push_back({0,0,height});
            break;
        }

   this->iterations = iterations;
   this->eje        = eje;
   this->top_lid    = false;
   this->bottom_lid = true;

   this->height     = height;
   this->radius     = radius;

   make_object(profile, eje);

}

