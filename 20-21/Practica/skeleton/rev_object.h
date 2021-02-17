#ifndef REV_OBJECT_H
#define REV_OBJECT_H

#include <vector>
#include <cmath>
#include "object3d.h"
#include "vertex.h"

typedef enum{X_AXIS, Y_AXIS, Z_AXIS} axis;

class rev_object: public _object3D
{
public:
        rev_object() = default;
        rev_object(const vector<_vertex3f> &profile, const int iterations = 15, const axis eje = Y_AXIS);

        vector<_vertex3f> profile;

    protected:
        int  iterations = 15;
        axis eje = Y_AXIS;
        bool top_lid = false;
        bool bottom_lid = false;

        _vertex3f v;

        void make_object(const vector<_vertex3f> &profile,const axis eje);
        void make_vertex(const vector<_vertex3f> &profile,const axis eje);
        void make_faces(const vector<_vertex3f> &profile);
        void make_lids(const vector<_vertex3f> &profile);

};

#endif // REV_OBJECT_H
