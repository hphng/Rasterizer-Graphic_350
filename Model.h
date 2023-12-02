#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <cmath>
#include <string>
#include "Triangle.h"
#include "Matrix.h"
#include "Color.h"
using namespace std;

class Model
{
public:
    Model();
    int numTriangles();
    Triangle3D operator[](int i);
    void transform(Matrix4 m);
    void readFromOBJFile(string filepath, Color pFillColor);
    void homogenize();

    void performBackfaceCulling(Vector4 eye, Vector4 spot);

private:
    vector<Triangle3D> triangles;
};

#endif