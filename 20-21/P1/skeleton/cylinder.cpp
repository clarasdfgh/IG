#include "cylinder.h"

_cylinder::_cylinder(const int iterations, const float Size, const float radius, const bool top_lid, const bool bottom_lid, const axis rotation_axis)
{
    switch(eje){
        case X_AXIS:
            profile.push_back({0,0,0});
            profile.push_back({0,radius,0});
            profile.push_back({Size,0,0});
        break;

        case Y_AXIS:
            profile.push_back({0,0,0});
            profile.push_back({radius,0,0});
            profile.push_back({0,Size,0});
        break;

        case Z_AXIS:
            profile.push_back({0,0,0});
            profile.push_back({0,radius,0});
            profile.push_back({0,0,Size});
        break;
    }

    this->iterations = iterations;
    this->bottom_lid = bottom_lid;
    this->top_lid = top_lid;
    this->Size = Size;
    this->radius = radius;
    this->eje = eje;

    make_object(/*profile,*/eje);
}
