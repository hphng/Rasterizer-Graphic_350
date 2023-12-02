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

#define WIDTH 100
#define HEIGHT 100

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

    // Raster myRaster(100, 100, White);
    // Model teapot = Model();
    // teapot.readFromOBJFile("./teapot.obj", Black);

    // Matrix4 m = Translate3D(50, 50, 0) * RotateZ3D(-45.07) * Scale3D(0.5, 0.5, 0.5);
    // teapot.transform(m);

    // myRaster.drawModel(teapot);
    
    // myRaster.writeToPPM();
    //___________________________________________
    
    //checkpoint 4:
    Raster myRaster(WIDTH, HEIGHT, White);

    Model teapot, bunny;
    teapot.readFromOBJFile("./teapot.obj", Red);
    bunny.readFromOBJFile("./bunny.obj", Blue);

    //Model Matrix
    Matrix4 modelMatrixTeapot = Translate3D(50, 50, -60) * RotateZ3D(45.0) * Scale3D(0.5, 0.5, 0.5);
    Matrix4 modelMatrixBunny = Translate3D(70, 30, -60) * RotateZ3D(-20.0) * Scale3D(500, 500, 500);


    //View Matrix
    Matrix4 viewMatrix = LookAt(Vector4(50, 50, 30, 1), Vector4(50, 50, -40, 1), Vector4(0, 1, 0, 0));

    // +++teapot.transform(viewMatrix * modelMatrixTeapot);

    //Perspective Matrix
    Matrix4 perspectiveMatrix = Perspective(70.0, myRaster.getWidth()/ myRaster.getHeight(), 0.01, 1000.0);

    //Viewport Matrix
    Matrix4 viewportMatrix = Viewport(0, 0, myRaster.getWidth(), myRaster.getHeight());

    teapot.transform(perspectiveMatrix * viewMatrix * modelMatrixTeapot);
    bunny.transform(perspectiveMatrix * viewMatrix * modelMatrixBunny);

    teapot.homogenize();
    bunny.homogenize();

    teapot.transform(viewportMatrix);
    bunny.transform(viewportMatrix);

    myRaster.drawModel(teapot);
    myRaster.drawModel(bunny);

    myRaster.writeToPPM();

    return 0;
}