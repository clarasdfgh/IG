#ifndef CYLINDER_H
#define CYLINDER_H

#include "rev_object.h"

class _cylinder: public rev_object
{
public:
    _cylinder(const int iterations=30,\
              const float height=2.0, const float radius=0.5, const axis eje=Y_AXIS);

protected:
    float height, radius;
};

#endif // CYLINDER_H
