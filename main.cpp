#include<iostream>
#include<vector>
#include<cmath>
#include "Color.cpp"
#include "Raster.cpp"
#include "Vector2.cpp"
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

    Raster ras = Raster(100, 100, White);

    // for(int j = 0; j< 20; j++){
    //     for(int i = 0; i < 20; i++){
    //         if(j %2 == 0){
    //             ras.setColorPixel(i, j, Red);
    //         }
    //         else{
    //             ras.setColorPixel(i, j, Red + Green);
    //         }
    //     }
    // }

    // for(int i = 0; i < 100; i++){
    //     ras.drawLine_DDA_Interpolated(i, 99, i, 0, Green + Red, Red);
    // }

    ras.drawLine_DDA_Interpolated(99,99,-10,10, Green + Red, Red);
    ras.drawLine_DDA_Interpolated(0, 99, 99, 0, Black, Blue);
    //ras.drawLine_DDA(10, 1, 10, 19, Red);
    ras.writeToPPM();
}