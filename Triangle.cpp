#include "Triangle.h"
#include <cmath>
#include <iostream>

Triangle2D::Triangle2D()
{
    // all of the vector and color are defined in color.h and vector.h
}

Triangle2D::Triangle2D(Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3)
{
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;

    this->c1 = c1;
    this->c2 = c2;
    this->c3 = c3;
}

Triangle2D::Triangle2D(Triangle3D T){
    v1 = Vector2(T.v1.x, T.v1.y);
    v2 = Vector2(T.v2.x, T.v2.y);
    v3 = Vector2(T.v3.x, T.v3.y);

    c1 = T.c1;
    c2 = T.c2;
    c3 = T.c3;
}

void Triangle2D::calculateBarycentricCoordinates(Vector2 p, float &lambda1, float &lambda2, float &lambda3)
{
    float areaAll = determinant(v2 - v3, v1 - v3);
    float area1 = determinant(v2 - v3, p - v3);
    float area2 = determinant(p - v3, v1 - v3);

    lambda1 = area1 / areaAll;
    lambda2 = area2 / areaAll;
    lambda3 = 1.0 - lambda1 - lambda2;
}

//___________
Triangle3D::Triangle3D()
{
    v1 = Vector4(0, 0, 0, 1);
    v2 = Vector4(0, 0, 0, 1);
    v3 = Vector4(0, 0, 0, 1);

    c1 = White;
    c2 = White;
    c3 = White;
}

Triangle3D::Triangle3D(Vector4 pV1, Vector4 pV2, Vector4 pV3, Color pC1, Color pC2, Color pC3){
    v1 = pV1;
    v2 = pV2;
    v3 = pV3;

    c1 = pC1;
    c2 = pC2;
    c3 = pC3;
}

void Triangle3D::transform(Matrix4 m){
    v1 = m * v1;
    v2 = m * v2;
    v3 = m * v3;
}
