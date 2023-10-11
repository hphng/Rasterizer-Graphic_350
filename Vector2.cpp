#include "Vector2.h"
#include<iostream>
#include<cmath>

Vector2::Vector2(){
    x = 0;
    y = 0;
}

Vector2::Vector2(float x, float y){
    this -> x = x;
    this -> y = y;
}

Vector2 Vector2::operator*(const float scalar){
    Vector2 result;

    result.x = x * scalar;
    result.y = y * scalar;

    return result;
}

Vector2 Vector2::operator+(Vector2 v){
    
    Vector2 result;

    result.x = this-> x + v.x;
    result.y = this-> y + v.y;

    return result;
}

Vector2 Vector2::operator-(Vector2 v){
    
    Vector2 result;

    result.x = this-> x - v.x;
    result.y = this-> y - v.y;

    return result;
}

float Vector2::magnitude(){
    float result = sqrt(x*x + y*y);

    return result;
}

float Vector2::dot(Vector2 v){
    float result = x * v.x + y * v.y;
    return result;
}

Vector2 Vector2::normalize(){

    float m = sqrt(x*x + y*y);
    m = 1/m;
    float newX = x * m;
    float newY = y * m;

    Vector2 result = Vector2(newX, newY);
    return result;
}

Vector2 Vector2::perpendicular(){
    Vector2 result = Vector2(-y, x);

    return result;
}

float determinant(Vector2 a, Vector2 b){
    float ans = b.x * a.y - a.x * b.y;

    return ans;
}


