#include "Vector.h"
#include <iostream>
#include <cmath>
using namespace std;
// ________________________________________________________________
// Vector2
Vector2::Vector2()
{
    x = 0;
    y = 0;
}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2 Vector2::operator*(const float scalar)
{
    Vector2 result;

    result.x = x * scalar;
    result.y = y * scalar;

    return result;
}

Vector2 Vector2::operator+(Vector2 v)
{

    Vector2 result;

    result.x = this->x + v.x;
    result.y = this->y + v.y;

    return result;
}

Vector2 Vector2::operator-(Vector2 v)
{

    Vector2 result;

    result.x = this->x - v.x;
    result.y = this->y - v.y;

    return result;
}

float Vector2::magnitude()
{
    float result = sqrt(x * x + y * y);

    return result;
}

float Vector2::dot(Vector2 v)
{
    float result = x * v.x + y * v.y;
    return result;
}

Vector2 Vector2::normalize()
{

    float m = sqrt(x * x + y * y);
    m = 1 / m;
    float newX = x * m;
    float newY = y * m;

    Vector2 result = Vector2(newX, newY);
    return result;
}

Vector2 Vector2::perpendicular()
{
    Vector2 result = Vector2(-y, x);

    return result;
}

float determinant(Vector2 a, Vector2 b)
{
    float ans = b.x * a.y - a.x * b.y;

    return ans;
}

//________________________________________________________________
// Vector4

Vector4::Vector4()
{
    x = 0;
    y = 0;
    z = 0;
    w = 0;
}

Vector4::Vector4(float pX, float pY, float pZ, float pW)
{
    this->x = pX;
    this->y = pY;
    this->z = pZ;
    this->w = pW;
}

Vector4 Vector4::operator*(const float scalar)
{
    Vector4 result;

    result.x = x * scalar;
    result.y = y * scalar;
    result.z = z * scalar;
    result.w = w * scalar;

    return result;
}

Vector4 Vector4::operator+(Vector4 v)
{
    Vector4 result;

    result.x = x + v.x;
    result.y = y + v.y;
    result.z = z + v.z;
    result.w = w + v.w;

    return result;
}

Vector4 Vector4::operator-(Vector4 v)
{
    Vector4 result;

    result.x = x - v.x;
    result.y = y - v.y;
    result.z = z - v.z;
    result.w = w - v.w;

    return result;
}

float Vector4::magnitude()
{
    float result = sqrt(x * x + y * y + z * z);
    return result;
}

float Vector4::dot(Vector4 v)
{
    float result = x * v.x + y * v.y + z * v.z + w * v.w;
    return result;
}

Vector4 Vector4::normalize()
{
    float m = sqrt(x * x + y * y + z * z);
    Vector4 result(x / m, y / m, z / m, w);

    return result;
}

Vector4 Vector4::cross(Vector4 v){
    float resX = y * v.z - z * v.y;
    float resY = z * v.x - x * v.z;
    float resZ = x * v.y - y * v.x;

    Vector4 result(resX, resY, resZ, 0);
    
    return result;
}

void Vector4::printVector4(){
    cout << "Vector4: " << endl;
    cout << x << endl << y << endl << z << endl << w << endl;
}
