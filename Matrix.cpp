#include "Vector.h"
#include "Matrix.h"
#include<iostream>
#include<cmath>

using namespace std;
Matrix4::Matrix4(){
    ix = 1.0; jx = 0.0; kx = 0.0; ox = 0.0;
    iy = 0.0; jy = 1.0; ky = 0.0; oy = 0.0;
    iz = 0.0; jz = 0.0; kz = 1.0; oz = 0.0;
    iw = 0.0; jw = 0.0; kw = 0.0; ow = 1.0;
}


Matrix4::Matrix4(float ix, float jx, float kx, float ox, 
                float iy, float jy, float ky, float oy, 
                float iz, float jz, float kz, float oz, 
                float iw, float jw, float kw, float ow){

    this -> ix = ix;    this -> jx = jx;
    this -> kx = kx;    this -> ox = ox;

    this -> iy = iy;    this -> jy = jy;
    this -> ky = ky;    this -> oy = oy;

    this -> iz = iz;    this -> jz = jz;
    this -> kz = kz;    this -> oz = oz;

    this -> iw = iw;    this -> jw = jw;
    this -> kw = kw;    this -> ow = ow;
}

Vector4 Matrix4::operator*(Vector4 other){
    float i = ix * other.x + jx * other.y + kx * other.z + ox * other.w;
    float j = iy * other.x + jy * other.y + ky * other.z + oy * other.w;
    float k = iz * other.x + jz * other.y + kz * other.z + oz * other.w;
    float w = iw * other.x + jw * other.y + kw * other.z + ow * other.w;

    Vector4 result(i, j, k, w);
    return result;
}

//this is left, other is right
Matrix4 Matrix4::operator*(Matrix4 other){
    Vector4 v1(other.ix, other.iy, other.iz, other.iw);
    Vector4 v2(other.jx, other.jy, other.jz, other.jw);
    Vector4 v3(other.kx, other.ky, other.kz, other.kw);
    Vector4 v4(other.ox, other.oy, other.oz, other.ow);

    Vector4 res1 = *this * v1;
    Vector4 res2 = *this * v2;
    Vector4 res3 = *this * v3;
    Vector4 res4 = *this * v4;

    Matrix4 result( res1.x, res2.x, res3.x, res4.x,
                    res1.y, res2.y, res3.y, res4.y,
                    res1.z, res2.z, res3.z, res4.z,
                    res1.w, res2.w, res3.w, res4.w);
    return result;
}


void Matrix4::printMatrix4(){
    cout << ix << " " << jx << " " << kx << " " << ox << endl;
    cout << iy << " " << jy << " " << ky << " " << oy << endl;
    cout << iz << " " << jz << " " << kz << " " << oz << endl;
    cout << iw << " " << jw << " " << kw << " " << ow << endl;
}

Matrix4 Translate3D(float tX, float tY, float tZ){
    Matrix4 result( 1, 0, 0, tX,
                    0, 1, 0, tY,
                    0, 0, 1, tZ,
                    0, 0, 0, 1  );
    return result;
}
Matrix4 Scale3D(float sX, float sY, float sZ){
    Matrix4 result( sX, 0, 0, 0,
                    0, sY, 0, 0,
                    0, 0, sZ, 0,
                    0, 0, 0, 1  );
    return result;
}

Matrix4 RotateX3D(float degrees){
    float r = degrees * M_PI /180.0;
    Matrix4 result( 1, 0, 0, 0,
                    0, cos(r), sin(r), 0,
                    0, -sin(r), cos(r), 0,
                    0, 0, 0, 1);
    return result;
}

Matrix4 RotateY3D(float degrees){
    float r = degrees * M_PI /180.0;
    Matrix4 result( cos(r), 0, -sin(r), 0,
                    0, 1, 0, 0,
                    sin(r), 0, cos(r), 0,
                    0, 0, 0, 1);
    return result;
}

Matrix4 RotateZ3D(float degrees){
    float r = degrees * M_PI /180.0;
    Matrix4 result( cos(r), sin(r), 0, 0,
                    -sin(r), cos(r), 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1);
    return result;
}

Matrix4 Rotate3D(float degreesX, float degreesY, float degreesZ){
    return RotateX3D(degreesX) * RotateY3D(degreesY) * RotateZ3D(degreesZ);
}

Matrix4 Rotate3D(float degrees, Vector4 vec){
    float a = atanf(vec.x/vec.z);
    float b = acosf(vec.y/vec.magnitude());

    Matrix4 result = RotateY3D(-a) * RotateX3D(-b) * RotateY3D(degrees) * RotateX3D(b) * RotateY3D(a);

    return result;
}

Matrix4 LookAt(Vector4 eye, Vector4 spot, Vector4 up){

    Vector4 look = spot - eye;
    Vector4 right = look.cross(up);
    Vector4 newUp = right.cross(look);

    look.normalize();
    right.normalize();
    newUp.normalize();

    Matrix4 orthonormal(right.x, right.y, right.z, 0,
                newUp.x, newUp.y, newUp.z, 0,
                -look.x, -look.y, -look.z, 0,
                0, 0, 0, 1);
    Matrix4 res = orthonormal *Translate3D(-eye.x, -eye.y, -eye.z);

    return res;
}

Matrix4 Orthographic(float minX, float maxX, float minY, float maxY, float minZ, float maxZ){
    Matrix4 defa;
    Matrix4 scale = Scale3D(2/(maxX - minX), 2/(maxY - minY), 2/(maxZ - minZ));
    Matrix4 translate = Translate3D(-(minX + maxX)/2, -(minY + maxY)/2, -(minZ + maxZ)/2);

    Matrix4 res = scale * translate * defa;

    return res;
}

Matrix4 Perspective(float fovY, float aspect, float nearZ, float farZ){
    float a = tan(fovY/2);
    float F = 1/a;

    float xCano = F/aspect;
    float yCano = F;
    float zCano1 = (farZ + nearZ)/(nearZ - farZ);
    float zCano2 = (2 * nearZ * farZ)/(nearZ - farZ);

    Matrix4 res(xCano, 0, 0, 0,
                0, F, 0, 0,
                0, 0, zCano1, zCano2,
                0, 0, -1, 0);
    return res;
}