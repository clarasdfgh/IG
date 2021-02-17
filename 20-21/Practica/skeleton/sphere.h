#ifndef SPHERE_H
#define SPHERE_H

#include "rev_object.h"

class _sphere: public rev_object
{
public:
    _sphere()=default;
    _sphere(int iterations=20, int radius=1.0);
};

#endif // SPHERE_H
