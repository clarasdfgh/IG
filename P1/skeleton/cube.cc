/*! \file
    Clara María Romero
    3ºB -- Informática Gráfica 20-21
    Práctica 1: Cubo y tetraedro
*/
#include "cube.h"

_cube::_cube(float Size)
{
    Vertices.resize(8);

    Vertices[0]=_vertex3f(-Size/2,Size/2,-Size/2);
    Vertices[1]=_vertex3f(Size/2,Size/2,-Size/2);
    Vertices[2]=_vertex3f(-Size/2,Size/2,Size/2);
    Vertices[3]=_vertex3f(Size/2,Size/2,Size/2);
    Vertices[4]=_vertex3f(-Size/2,-Size/2,-Size/2);
    Vertices[5]=_vertex3f(Size/2,-Size/2,Size/2);
    Vertices[6]=_vertex3f(-Size/2,-Size/2,Size/2);
    Vertices[7]=_vertex3f(Size/2,-Size/2,Size/2);

    Triangles.resize(12);

    Triangles[0]=_vertex3ui(0,1,2);
    Triangles[1]=_vertex3ui(1,2,3);
    Triangles[2]=_vertex3ui(0,2,4);
    Triangles[3]=_vertex3ui(2,5,4);
    Triangles[4]=_vertex3ui(2,3,5);
    Triangles[5]=_vertex3ui(3,6,5);
    Triangles[6]=_vertex3ui(3,1,6);
    Triangles[7]=_vertex3ui(1,7,6);
    Triangles[8]=_vertex3ui(1,0,7);
    Triangles[9]=_vertex3ui(0,4,7);
    Triangles[10]=_vertex3ui(5,6,4);
    Triangles[11]=_vertex3ui(6,7,4);
}
