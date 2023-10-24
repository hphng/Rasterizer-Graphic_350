#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vector.h"
#include "Color.h"
#include "Matrix.h"

struct Triangle3D;

struct Triangle2D{
    Vector2 v1;
    Vector2 v2;
    Vector2 v3;

    Color c1;
    Color c2;
    Color c3;

    Triangle2D();
    Triangle2D(Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3);
    Triangle2D(Triangle3D T);

    void calculateBarycentricCoordinates(Vector2 p, float& lambda1, float& lambda2, float& lambda3);
};

struct Triangle3D{
    Vector4 v1;
    Vector4 v2;
    Vector4 v3;
    
    Color c1;
    Color c2;
    Color c3;

    Triangle3D();
    Triangle3D(Vector4 pV1, Vector4 pV2, Vector4 pV3, Color pC1, Color pC2, Color pC3);
    void transform(Matrix4 m);
};

#endif