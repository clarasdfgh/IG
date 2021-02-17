#ifndef OBJECT_REVOLUTION_H
#define OBJECT_REVOLUTION_H
#include <vector>
#include <cmath>
#include "object3d.h"
#include "vertex.h"

typedef enum{X_AXIS, Y_AXIS, Z_AXIS} axis;


class object_revolution : public _object3D
{
public:
    object_revolution() = default;
    object_revolution(const vector<_vertex3f> &profile, const int iterations, \
                      const bool top_lid, const bool bottom_lid, \
                      const axis eje = Y_AXIS);
    vector<_vertex3f> profile;
protected:
    int iterations;
    bool top_lid, bottom_lid;
    axis eje = Y_AXIS;

    void make_object(/*const vector<_vertex3f> &profile,*/ const axis eje);
};

#endif // OBJECT_REVOLUTION_H
