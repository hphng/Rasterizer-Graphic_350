#include <iostream>
#include <vector>
#include <cmath>
#include "Color.cpp"
#include "Raster.cpp"
#include "Vector.cpp"
#include "Triangle.cpp"
#include "Matrix.cpp"
#include "Model.cpp"
using namespace std;

int main()
{

    // Color a = Color(0.3, 1.0, 0.1);
    // Color b = Color(0.2, 0.4, 0.6);
    // Color c = Color(3.0f, 3.0f, 3.0f);

    // Color x = a + b;
    // Color y = a - b;
    // Color z = a * 2.0f;

    // Color red = Red;
    // Color black = Black;

    // // x.printColor();
    // // y.printColor();
    // // z.printColor();
    // // red.printColor();
    // // black.printColor();

    // Raster ras = Raster(100, 100, White);

    // // for(int i = 0; i < 100; i++){
    // //     ras.drawLine_DDA_Interpolated(i, 99, i, 0, Green + Red, Red);
    // // }

    // ras.drawLine_DDA_Interpolated(99, 99, -10, 10, Green + Red, Red);
    // ras.drawLine_DDA_Interpolated(-30, 10, 120, 10, Black, Blue);

    // // ras.drawLine_DDA(10, 1, 10, 19, Red);

    // Triangle2D myTriangle(Vector2(-30, 19), Vector2(120, 15), Vector2(45, 90), Red, Blue, Green);
    // ras.drawTriangle_Barycentric(myTriangle);

    // // ras.drawLine_DDA_Interpolated(2,10,2,70,Red,Green);

    // ras.writeToPPM();
    //_________________________________________
    // Raster myRaster(100, 100, White);
    // Triangle3D t(Vector4(0, 0, 0, 1), Vector4(40, 0, 0, 1), Vector4(40, 40, 0, 1), Red, Blue, Green);

    // Matrix4 m = Translate3D(20, 10, 10) * RotateZ3D(-100.0);
    // t.transform(m);
    // myRaster.drawTriangle3D_Barycentric(t);
    // myRaster.writeToPPM();
    //_________________________________________

    Raster myRaster(100, 100, White);
    Model teapot = Model();
    teapot.readFromOBJFile("./teapot.obj", Black);

    Matrix4 m = Translate3D(50, 50, 0) * RotateZ3D(-45.07) * Scale3D(0.5, 0.5, 0.5);
    teapot.transform(m);

    myRaster.drawModel(teapot);
    
    myRaster.writeToPPM();


    return 0;
}