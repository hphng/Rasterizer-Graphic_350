#include "Color.h"
#include <cmath>

using namespace std;

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