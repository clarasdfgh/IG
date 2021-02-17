#include "ply_object.h"

ply_object::ply_object(const char *file)
{
   _file_ply archivo;
   archivo.open(file);
   archivo.read(Vertices, Triangles);
   archivo.close();
}
