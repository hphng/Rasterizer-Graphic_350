#include "Triangle2D.h"
#include<cmath>
#include<iostream>

Triangle2D::Triangle2D(){
    //all of the vector and color are defined in color.h and vector.h
}

Triangle2D::Triangle2D(Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3){
    this -> v1 = v1;
    this -> v2 = v2;
    this -> v3 = v3;

    this -> c1 = c1;
    this -> c2 = c2;
    this -> c3 = c3;
}

void Triangle2D::calculateBarycentricCoordinates(Vector2 p, float& lambda1, float& lambda2, float& lambda3){
    float areaAll = determinant(v2 - v3, v1 - v3);
    float area1 = determinant(v2 - v3, p - v3);
    float area2 = determinant(p - v3, v1 - v3);

    lambda1 = area1/areaAll;
    lambda2 = area2/areaAll;
    lambda3 = 1.0 - lambda1 - lambda2;
}