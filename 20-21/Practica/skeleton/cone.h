#ifndef CONE_H
#define CONE_H

#include "rev_object.h"

class _cone: public rev_object
{
public:
    _cone(const int iterations=30,\
          const float height=2.0, const float radius=0.5, const axis eje=Y_AXIS);

protected:
    //vector<_vertex3f> &profile;
    float height, radius;
};

#endif // CONE_H
