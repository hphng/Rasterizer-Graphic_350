#include "Color.h"
#include <cmath>
#include<iostream>

Color::Color(){
    red = 0;
    green = 0;
    blue = 0;
}

Color::Color(float pRed, float pGreen, float pBlue){
    red = pRed;
    green = pGreen;
    blue = pBlue;
}

void Color::clamp(){
    red = fmin(fmax(red, 0), 1);
    green = fmin(fmax(green, 0), 1);
    blue = fmin(fmax(blue, 0), 1);
}

Color Color::operator+(Color c){

    //Color result = Color(red + c.red, green + c.green, blue + c.blue);

    Color result;

    result.red = this -> red + c.red;
    result.green = this -> green + c.green;
    result.blue = this -> blue + c.blue;
    
    result.clamp();
    return result;
}

Color Color::operator-(Color c){

    //Color result = Color(red - c.red, green - c.green, blue - c.blue);

    Color result;

    result.red = this -> red - c.red;
    result.green = this -> green - c.green;
    result.blue = this -> blue - c.blue;

    result.clamp();
    return result;
}

Color Color::operator*(const float scalar){

    //Color result = Color(red * scalar, green * scalar, blue * scalar);

    Color result;

    result.red = this -> red * scalar;
    result.green = this -> green * scalar;
    result.blue = this -> blue * scalar;

    result.clamp();
    return result;
}

void Color::printColor(){
    std::cout << red << " " << green << " " << blue << std::endl;
}