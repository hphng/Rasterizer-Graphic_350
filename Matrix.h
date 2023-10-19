#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h"

struct Matrix4
{
    float ix, jx, kx, ox;
    float iy, jy, ky, oy;
    float iz, jz, kz, oz;
    float iw, jw, kw, ow;

    Matrix4();
    Matrix4(float ix, float jx, float kx, float ox,
            float iy, float jy, float ky, float oy,
            float iz, float jz, float kz, float oz,
            float iw, float jw, float kw, float ow);
    Vector4 operator*(Vector4 other);
    Matrix4 operator*(Matrix4 other);
    void printMatrix4();
};

Matrix4 Translate3D(float tX, float tY, float tZ);
Matrix4 Scale3D(float sX, float sY, float sZ);
Matrix4 RotateX3D(float degrees);
Matrix4 RotateY3D(float degrees);
Matrix4 RotateZ3D(float degrees);
Matrix4 Rotate3D(float degreesX, float degreesY, float degreesZ);
Matrix4 Rotate3D(float degrees, Vector4 vec);
#endif