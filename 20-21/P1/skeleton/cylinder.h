#ifndef CYLINDER_H
#define CYLINDER_H
#include "object_revolution.h"

class _cylinder:public object_revolution
{
public:
    _cylinder(const int iterations, const float Size=1.0, const float radius=0.5, const bool top_lid=true, const bool bottom_lid=true, const axis rotation_axis=Y_AXIS);
    float Size, radius;
};

#endif // CYLINDER_H
