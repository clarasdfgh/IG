#include "object_ply.h"

object_ply::object_ply(const char *file)
{
   _file_ply archivo;
   archivo.open(file);
   archivo.read(Vertices, Triangles);
   archivo.close();
}
