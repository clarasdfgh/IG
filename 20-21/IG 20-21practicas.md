# IG 20-21: guía y seguimiento de prácticas

## Práctica 1: modelado y renderizado de objetos 3D simples

> 1. Crear la clase Cube y visualización de una instancia
> 2. Crear la clase Tetrahedron y visualización de una instancia
> 3. Modo Fill y modo Chess

### 1. Class Cube

```C++
//cube.h
#ifndef CUBE_H
#define CUBE_H

#include "object3d.h"

class _cube:public _object3D
{
public:
    _cube(float Size=1.0);
};

#endif // CUBE_H

```

```c++
//cube.cpp
#include "cube.h"

_cube::_cube(float Size)
{
    Vertices.resize(8);

    Vertices[0]=_vertex3f(-Size/2,  Size/2,     -Size/2);
    Vertices[1]=_vertex3f(Size/2,   Size/2,     -Size/2);
    Vertices[2]=_vertex3f(-Size/2,  Size/2,     Size/2);
    Vertices[3]=_vertex3f(Size/2,   Size/2,     Size/2);
    Vertices[4]=_vertex3f(-Size/2, -Size/2,    -Size/2);
    Vertices[5]=_vertex3f(Size/2,  -Size/2,    -Size/2);
    Vertices[6]=_vertex3f(-Size/2, -Size/2,    Size/2);
    Vertices[7]=_vertex3f(Size/2,  -Size/2,    Size/2);

    Triangles.resize(12);

    Triangles[0]=_vertex3ui(0,1,2);
    Triangles[1]=_vertex3ui(2,3,1);
    Triangles[2]=_vertex3ui(2,3,6);
    Triangles[3]=_vertex3ui(3,6,7);
    Triangles[4]=_vertex3ui(3,1,7);
    Triangles[5]=_vertex3ui(1,5,7);
    Triangles[6]=_vertex3ui(6,7,5);
    Triangles[7]=_vertex3ui(5,4,6);
    Triangles[8]=_vertex3ui(2,0,6);
    Triangles[9]=_vertex3ui(0,4,6);
    Triangles[10]=_vertex3ui(0,4,5);
    Triangles[11]=_vertex3ui(0,1,5);
}

```

### 2. Class Tetrahedron

```C++
//tetrahedron.h
#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "object3d.h"

class _tetrahedron:public _object3D
{
public:
  _tetrahedron(float Size=1.0);
};

#endif

```

```c++
//tetrahedron.cpp
#include "tetrahedron.h"

_tetrahedron::_tetrahedron(float Size)
{
  Vertices.resize(4);

  Vertices[0]=_vertex3f(-Size/2,-Size/2,-Size/2);
  Vertices[1]=_vertex3f(0,-Size/2,Size/2);
  Vertices[2]=_vertex3f(Size/2,-Size/2,-Size/2);
  Vertices[3]=_vertex3f(0,Size/2,0);

  Triangles.resize(4);

  Triangles[0]=_vertex3ui(0,1,3);
  Triangles[1]=_vertex3ui(1,2,3);
  Triangles[2]=_vertex3ui(2,0,3);
  Triangles[3]=_vertex3ui(0,2,1);
}

```

### 3. Fill & Chess

#### Object3D.cc

```c++
void _object3D::draw_line()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        glBegin(GL_TRIANGLES);
        for (unsigned int i=0;i<Triangles.size();i++){
          glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
          glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
          glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
          }
        glEnd();
}


/*****************************************************************************/

void _object3D::draw_fill()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
         glBegin(GL_TRIANGLES);
         for (unsigned int i=0;i<Triangles.size();i++){
           glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
           glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
           glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
         }
         glEnd();
}


/*****************************************************************************/

void _object3D::draw_chess()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        glBegin(GL_TRIANGLES);

        for (unsigned int i=0;i<Triangles.size();i++){
          i%2==0? glColor3fv((GLfloat *) &BLACK) : glColor3fv((GLfloat *) &RED);

          glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
          glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
          glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);

        }
        glEnd();
}
```



## Práctica 2: modelos PLY y poligonales

> 1. Creación de una clase para modelos PLY
> 2. Creación de una clase para objetos de revolución
> 3. Permitir que los puntos de un perfil tengan cualquier dirección
> 4. Crear la clase Cone
> 5. Crear la clase Cylinder
> 6. Crear la clase Sphere
>
> Extra: permitir que la curva generatriz se defina en cualquiera de los ejes X, Y, Z

### 1.

### 2.Class rev_obj

### 3.Class Cone

### 4.Class Cylinder

### 5.Class Sphere

## Práctica 3: modelos jerárquicos

> 1. Creación de un modelo jerárquico y sus clases correspondientes que tenga al menos 5 niveles y 3 grados de libertad
> 2. Creación del grafo modelo
> 3. 

## Práctica 4:

## Práctica 5: