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