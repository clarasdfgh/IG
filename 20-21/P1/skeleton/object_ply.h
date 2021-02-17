#ifndef OBJECT_PLY_H
#define OBJECT_PLY_H
#include "object3d.h"
#include "file_ply_stl.h"


class object_ply:public _object3D
{
public:
    object_ply(const char *file);
};

#endif // OBJECT_PLY_H
