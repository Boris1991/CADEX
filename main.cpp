#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <omp.h>     // for OpenMP

#include "Point3D.h"
#include "Vector3D.h"

#include "Curves.h"
#include "Circles.h"
#include "Elipses.h"
#include "Helixes3D.h"


Curves* createCurve(int curveType, double param1, double param2) {
    switch (curveType) {
        case 0:
            return new Circles(param1);
        case 1:
            return new Elipses(param1, param2);
        case 2:
            return new Helixes3D(param1, param2);
        default:
            return nullptr;
    }
}

Curves* createRandomCurve() {
    // Generate a random curve from 0 to 2
    int curveType = rand() % 3;

    // Generate random double parameters from 0.001 to 1000
    double param1 = (double) rand()/RAND_MAX*1000+0.001;
    double param2 = (double) rand()/RAND_MAX*1000+0.001;

    return createCurve(curveType, param1, param2);
}

// Comparison for circles based on radius
bool compareCirclesByRadius(Circles* circle1, Circles* circle2) {
    return (circle1->getRadius() < circle2->getRadius());
}

int main() {
    
    srand((unsigned)time(nullptr));
    //////////////////////////////////////////////////////////////////
    //2. Create an array with random meanings of forms and parameters
    //////////////////////////////////////////////////////////////////
    
    int N = 150000; // Size of the array
    std::vector<Curves*> v_curves(N);
    std::cout << "v_curves size = " << v_curves.size() << std::endl;
    //Create array
    for (int i = 0; i < N; i++) {
	v_curves[i] = createRandomCurve();
    }
    
    //////////////////////////////////////////////////////////////////
    // Printing coordinates of point and vector at the parameter pi/4
    //////////////////////////////////////////////////////////////////
    for (Curves* curve : v_curves) {
	curve->getType();
	std::cout << ":\t\t";
        Point3D point = curve->getPoint(M_PI_4);
	point.Show();
	std::cout << ",\t\t";
	Vector3D derivative = curve->getFirstDerivative(M_PI_4);
	derivative.Show();
	std::cout << ". " << std::endl;
    }
    
    ////////////////////////////////////////////////////////////////
    // 4. Populating a new array by circles from former array
    /////////////////////////////////////////////////////////////////
    std::vector<Circles*> v_circles;
    
    for (Curves* curve : v_curves) {
	Circles* circle = dynamic_cast<Circles*>(curve);
	 
	if (circle) {
            // If it's a circle, add it to the second container
            v_circles.push_back(circle);
        }
    } 
    
    ///////////////////////////////////////////////////////////////////
    // 5.  Sorting by radii each circle
    ///////////////////////////////////////////////////////////////////
    std::sort(v_circles.begin(), v_circles.end(), compareCirclesByRadius);
    for(Circles* circle : v_circles) {
	std::cout << "Radius = " << circle->getRadius() << std::endl;
    }
    
    ///////////////////////////////////////////////////////////////////
    // 6.  Sum of radii using openMP
    ///////////////////////////////////////////////////////////////////
    double sumRadius(0);
    #pragma omp parallel
    for (int i = 0; i < v_circles.size(); ++i) {
	sumRadius += v_circles[i]->getRadius();
    }

    std::cout << "The sum of the circle radii " << sumRadius << std::endl;
    
    // Delete each element in the vector
    for (Curves* curve : v_curves) {
        delete curve;
    }
    
    return 0;
}

