#ifndef VECTOR3D_H
#define VECTOR3D_H 1


// Point3D structure definition
struct Vector3D {
    double x, y, z;
    // Constructors
    Vector3D() : x(0.0), y(0.0), z(0.0) {};
    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {};
    
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void Show();
};

#endif

