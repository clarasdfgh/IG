#ifndef OBJECT_PLY_H
#define OBJECT_PLY_H
#include "object3d.h"
#include "file_ply_stl.h"


class ply_object:public _object3D
{
public:
    ply_object(const char *file);
};

#endif // OBJECT_PLY_H
