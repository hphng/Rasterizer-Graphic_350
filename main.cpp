#include<iostream>
#include<vector>
#include<cmath>
#include "Color.cpp"
using namespace std;

int main(){


    Color a = Color(0.3, 1.0, 0.1);
    Color b = Color(0.2, 0.4, 0.6);
    Color c = Color(3.0f, 3.0f, 3.0f);

    Color x = a + b;
    Color y = a - b;
    Color z = a * 2.0f;

    x.printColor();
    y.printColor();
    z.printColor();

    
}