#ifndef POINT3D_H
#define POINT3D_H 1

// Point3D structure definition
struct Point3D {
private:
    double x, y, z;
public: 
    // Constructors
    Point3D() : x(0.0), y(0.0), z(0.0) {};
    Point3D(double xCoord, double yCoord, double zCoord) : x(xCoord), y(yCoord), z(zCoord) {};
    
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void Show();
};

#endif

