#include<iostream>
#include<vector>
#include<cmath>
#include "Color.cpp"
#include "Raster.cpp"
// #include<iostream>
// #include<fstream>
using namespace std;

int main(){


    Color a = Color(0.3, 1.0, 0.1);
    Color b = Color(0.2, 0.4, 0.6);
    Color c = Color(3.0f, 3.0f, 3.0f);

    Color x = a + b;
    Color y = a - b;
    Color z = a * 2.0f;

    Color red = Red;
    Color black = Black;

    x.printColor();
    y.printColor();
    z.printColor();
    red.printColor();
    black.printColor();

    Raster ras = Raster(5, 4, White);

    for(int j = 0; j< 4; j++){
        for(int i = 0; i < 5; i++){
            if(j %2 == 0){
                ras.setColorPixel(i, j, Black);
            }
            else{
                ras.setColorPixel(i, j, White);
            }
        }
    }
    ras.writeToPPM();


}