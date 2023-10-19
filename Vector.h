#ifndef VECTOR_H
#define VECTOR_H

struct Vector2{
    float x;
    float y;

    Vector2();
    Vector2(float x, float y);

    Vector2 operator*(const float scalar);
    Vector2 operator+(Vector2 v);
    Vector2 operator-(Vector2 v);

    float magnitude();
    float dot(Vector2 v);

    Vector2 normalize();
    Vector2 perpendicular();
};

float determinant(Vector2 a, Vector2 b);

struct Vector4{
    float x;
    float y;
    float z;
    float w;

    Vector4();
    Vector4(float pX, float pY, float pZ, float pW);

    Vector4 operator*(const float scalar);
    Vector4 operator+(Vector4 v);
    Vector4 operator-(Vector4 v);

    float magnitude();
    float dot(Vector4 v);
    Vector4 normalize();

    void printVector4();
};

#endif