#include "Raster.h"
#include <iostream>
#include <fstream>
#include "Vector.h"
#include "Triangle.h"
#include "Color.h"
#include <cmath>
#include <limits>
using namespace std;

Raster::Raster(){
    this -> width = 0;
    this -> height = 0;
    this -> pixels = NULL;
    this -> depthPixels = NULL;
}

Raster::Raster(int pWidth, int pHeight, Color pFillColor){
    this -> width = pWidth;
    this -> height = pHeight;
    
    int size = pWidth * pHeight;
    this -> pixels = new Color[size];
    this -> depthPixels = new float[size];

    float maxi = numeric_limits<float>::max();

    for(int i = 0; i < size; i++){
        pixels[i] = pFillColor;
        depthPixels[i] = maxi;
    }
}

Raster::~Raster(){
    delete[] pixels;
    delete[] depthPixels;
}

int Raster::getWidth(){
    return width;
}

int Raster::getHeight(){
    return height;
}

Color Raster::getColorPixel(int x, int y){
    int w = getWidth();
    int h = getHeight();

    int index = ( h-1 - y) * w + x;

    return pixels[index];
}

void Raster::setColorPixel(int x, int y, Color pFillColor){
    int w = getWidth();
    int h = getHeight();
    if(x >= w || y >=h || x < 0 || y < 0){
        return;
    }
    int index = ( h-1 - y) * w + x;
    pixels[index] = pFillColor;
}

void Raster::clear(Color pFillColor){
    int size = *(&pixels + 1) - pixels;
    for(int i = 0; i < size; i++){
        pixels[i] = pFillColor;
    }
}

//___________depth___________________
float Raster::getDepthPixel(int x, int y){
    int w = getWidth();
    int h = getHeight();

    int index = ( h-1 - y) * w + x;

    return depthPixels[index];
}

void Raster::setDepthPixel(int x, int y, float depth){
    int w = getWidth();
    int h = getHeight();
    if(x >= w || y >=h || x < 0 || y < 0){
        return;
    }
    int index = ( h-1 - y) * w + x;
    depthPixels[index] = depth;
}

void Raster::clear(float depth){
    int size = *(&depthPixels + 1) - depthPixels;
    for(int i = 0; i < size; i++){
        depthPixels[i] = depth;
    }
}
//___________end_of_depth____________

void Raster::writeToPPM(){
    int w = getWidth();
    int h = getHeight();

    ofstream MyFile("FRAME_BUFFER.ppm");

    MyFile << "P3" << endl;
    MyFile << w << " " << h << endl;
    MyFile << "255" << endl;

    for(int j = h-1; j >= 0; j--){
        for(int i = 0; i < w; i++){
            Color index = getColorPixel(i, j);
            MyFile << round(index.red * 255) << " "; 
            MyFile << round(index.green * 255) << " ";
            MyFile << round(index.blue * 255) << " ";
        }
        MyFile << endl;
    }

    MyFile.close();
}

void Raster::swap(float& x1, float& y1, float& x2, float& y2){
    float a = x1;
    x1 = x2;
    x2 = a;

    float b = y1;
    y1 = y2;
    y2 = b;
}

void Raster::swap_Interpolated(float& x1, float& y1, float& x2, float& y2, Color& color1, Color& color2){
    float a = x1;
    x1 = x2;
    x2 = a;

    float b = y1;
    y1 = y2;
    y2 = b;

    Color c = color1;
    color1 = color2;
    color2 = c;
}

void Raster::drawLine_DDA(float x1, float y1, float x2, float y2, Color fillColor){
    //horizontal line
    if(y1 == y2){
        int y = y1;
        int l = fmin(x1, x2);
        int r = fmax(x1, x2);
        for(int i = l; i <=r; i++){
            setColorPixel(i, y, fillColor);
        }
        return;
    //vertical line
    } else if(x1 == x2){
        int x = x1;
        int b = fmin(y1, y2);
        int t = fmax(y1, y2);
        for(int i = b; i <=t; i++){
            setColorPixel(x, i, fillColor);
        }
        return;
    }

    float m = (y1 - y2)/(x1-x2);
    float b = y1 - m*x1;

    //checking with slope
    if(abs(m) <= 1){
        if(x1 > x2){
            swap(x1, y1, x2, y2);
        }
        float y = y1;
        for(int x = x1; x <= x2; x++ ){
            setColorPixel(x, round(y), fillColor);
            y+= m;
        }
    }else{
        if(y2 < y1){
            swap(x1, y1, x2, y2);
        }
        m = (x2-x1)/(y2-y1);
        float x = x2;
        for(int y = y2; y>=y1; y--){
            setColorPixel(round(x), y, fillColor);
            x-=m;
        }
    }
}

void Raster::drawLine_DDA_Interpolated(float x1, float y1, float x2, float y2, Color color1, Color color2){
    //horizontal line
    if(y1 == y2){
        int y = y1;
        int l = fmin(x1, x2);
        int r = fmax(x1, x2);

        for(int i = l; i <=r; i++){

            float ratio = float((i-l))/(r-l);
            Color interpolatedColor = color2*ratio + color1*(1.0 - ratio);
            setColorPixel(i, y, interpolatedColor);
        }
        return;
    //vertical line
    } else if(x1 == x2){
        int x = x1;
        int b = fmin(y1, y2);
        int t = fmax(y1, y2);
        for(int i = b; i <=t; i++){

            float ratio = float((i-b))/(t-b);
            Color interpolatedColor = color2 * ratio + color1*(1.0 - ratio); 
            setColorPixel(x, i, interpolatedColor);
        }
        return;
    }

    float m = (y1 - y2)/(x1-x2);
    float b = y1 - m*x1;

    //checking with slope
    if(abs(m) <= 1){
        if(x1 > x2){
            swap_Interpolated(x1, y1, x2, y2, color1, color2);
        }
            Vector2 point1 = Vector2(x1, y1);
            Vector2 point2 = Vector2(x2, y2);

        float y = y1;
        for(int x = x1; x <= x2; x++ ){
            Vector2 pointp = Vector2(x, y);

            Vector2 point12 = point2 - point1;
            Vector2 point1p = pointp - point1;

            float ratio = point1p.magnitude()/point12.magnitude();
            Color interpolatedColor = color2 * ratio + color1*(1.0 - ratio); 
            setColorPixel(x, round(y), interpolatedColor);
            y+= m;
        }
    }else{
        if(y2 < y1){
            swap_Interpolated(x1, y1, x2, y2, color1, color2);
        }
        Vector2 point1 = Vector2(x1, y1);
        Vector2 point2 = Vector2(x2, y2);

        m = (x2-x1)/(y2-y1);
        float x = x2;
        for(int y = y2; y>=y1; y--){
            Vector2 pointp = Vector2(x, y);

            Vector2 point12 = point2 - point1;
            Vector2 point1p = pointp - point1;

            float ratio = point1p.magnitude()/point12.magnitude();
            Color interpolatedColor = color2 * ratio + color1*(1.0 - ratio); 
            setColorPixel(round(x), y, interpolatedColor);
            x-=m;
        }
    }
}

void Raster::drawTriangle2D_DotProduct(Triangle2D tri){
    int h = getHeight();
    int w = getWidth();

    Vector2 edge13 = tri.v1 - tri.v3;
    Vector2 edge21 = tri.v2 - tri.v1;
    Vector2 edge32 = tri.v3 - tri.v2;

    Vector2 perp13 = edge13.perpendicular();
    Vector2 perp21 = edge21.perpendicular();
    Vector2 perp32 = edge32.perpendicular();


    int maxH = fmax(fmax(tri.v1.x, tri.v2.x), tri.v3.x);
    int minH = fmin(fmin(tri.v1.x, tri.v2.x), tri.v3.x);
    int maxW = fmax(fmax(tri.v1.y, tri.v2.y), tri.v3.y);
    int minW = fmin(fmin(tri.v1.y, tri.v2.y), tri.v3.y);


    for(int i = minH; i < maxH; i++){
        for(int j = minW; j < maxW; j++){
            Vector2 p = Vector2(i, j);
            
            Vector2 g13 = p - tri.v1;
            Vector2 g21 = p - tri.v2;
            Vector2 g32 = p - tri.v3;

            float result13 = perp13.dot(g13);
            float result21 = perp21.dot(g21);
            float result32 = perp32.dot(g32);

            if(result13 >= 0 && result21 >= 0 && result32 >= 0){
                setColorPixel(i, j, tri.c1);
            }
        }
    }
}

void Raster::drawTriangle3D_Barycentric(Triangle3D T3D){

    Triangle2D T(T3D);
    int h = getHeight();
    int w = getWidth();

    int maxH = fmax(fmax(T.v1.x, T.v2.x), T.v3.x);
    int minH = fmin(fmin(T.v1.x, T.v2.x), T.v3.x);
    int maxW = fmax(fmax(T.v1.y, T.v2.y), T.v3.y);
    int minW = fmin(fmin(T.v1.y, T.v2.y), T.v3.y);

    for(int i = minH; i <= maxH; i++){
        for(int j = minW; j <= maxW; j++){
            Vector2 p(i, j);
            float w1, w2, w3;
            T.calculateBarycentricCoordinates(p, w1, w2, w3);

            if(w1 >= 0 && w2 >=0 && w3 >= 0){
 
                Color fill = T.c1*w1 + T.c2*w2 + T.c3*w3;
                //setColorPixel(i, j, fill);

                float depth = T3D.v1.z*w1 + T3D.v2.z*w2 + T3D.v3.z*w3;
                if(depth < getDepthPixel(i, j)){
                    setColorPixel(i, j, fill);
                    setDepthPixel(i, j, depth);
                }
            }
        }
    }
}

void Raster::drawModel(Model model){
    for(int i = 0; i < model.numTriangles(); i++){
        drawTriangle3D_Barycentric(model[i]);
    }
}