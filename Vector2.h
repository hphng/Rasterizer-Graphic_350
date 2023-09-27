#ifndef VECTOR2_H
#define VECTOR2_H

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

#endif