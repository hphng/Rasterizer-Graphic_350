#include <iostream>
#include <vector>
#include <cmath>
#include "Color.cpp"
#include "Raster.cpp"
#include "Vector.cpp"
#include "Triangle.cpp"
#include "Matrix.cpp"
using namespace std;

int main()
{

    Color a = Color(0.3, 1.0, 0.1);
    Color b = Color(0.2, 0.4, 0.6);
    Color c = Color(3.0f, 3.0f, 3.0f);

    Color x = a + b;
    Color y = a - b;
    Color z = a * 2.0f;

    Color red = Red;
    Color black = Black;

    // x.printColor();
    // y.printColor();
    // z.printColor();
    // red.printColor();
    // black.printColor();

    Raster ras = Raster(100, 100, White);

    // for(int i = 0; i < 100; i++){
    //     ras.drawLine_DDA_Interpolated(i, 99, i, 0, Green + Red, Red);
    // }

    ras.drawLine_DDA_Interpolated(99, 99, -10, 10, Green + Red, Red);
    ras.drawLine_DDA_Interpolated(-30, 10, 120, 10, Black, Blue);

    // ras.drawLine_DDA(10, 1, 10, 19, Red);

    Triangle2D myTriangle(Vector2(-30, 19), Vector2(120, 15), Vector2(45, 90), Red, Blue, Green);
    ras.drawTriangle_Barycentric(myTriangle);

    // ras.drawLine_DDA_Interpolated(2,10,2,70,Red,Green);

    ras.writeToPPM();

    // Vector4 v4 = Vector4(3, 4, 5, 6);
    // Matrix4 ma = Matrix4(1.0, 0.0, 0.0, 0.0,
    //                      10.0, 1.0, 0.0, 0.0,
    //                      0.0, 0.0, 1.0, 0.0,
    //                      0.0, 0.0, 0.0, 1.0);
    // Matrix4 mb = Matrix4(1.0, 0.0, 0.0, 0.0,
    //                      0.0, 1.0, 0.0, 0.0,
    //                      0.0, 0.0, 1.0, 0.0,
    //                      0.0, 0.0, 0.0, 1.0);

    // Matrix4 A = Matrix4(1, 2, 3, 4,
    //                     5, 6, 7, 8,
    //                     9, 10, 11, 12,
    //                     13, 14, 15, 16);
    // Matrix4 B = Matrix4(17, 18, 19, 20, 
    //                     21, 22, 23, 24,
    //                     25, 26, 27, 28, 
    //                     29, 30, 31, 32);
    // Matrix4 C = A * B;
    // C.printMatrix4();
}