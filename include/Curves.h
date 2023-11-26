#ifndef CURVES_H
#define CURVES_H 1

#include "Point3D.h"
#include "Vector3D.h"

#include "Curves.h"

class Curves {
    double t;

public:
    
    Curves();
    virtual ~Curves();
    // Return a 3D point at parameter t along the curve
    virtual Point3D getPoint(double t);

    // Return the first derivative (3D vector) at parameter t along the curve
    virtual Vector3D getFirstDerivative(double t);
    
    // Show type
    virtual void getType();
 
};

#endif
