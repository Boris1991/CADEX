#ifndef ELIPSES_H
#define ELIPSES_H 1

#include "Curves.h"
#include "Point3D.h"
#include "Vector3D.h"

class Elipses: public Curves {
	//Ellipse are defined thoughout small and big radiuses
	double radiusX, radiusY;
	
public:
	
	Elipses(double rx, double ry);
	~Elipses() override;
	
	Point3D getPoint(double t) override;
    Vector3D getFirstDerivative(double t) override;
    void getType() override;

	
};

#endif
