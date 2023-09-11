#include "Raster.h"
#include <iostream>
#include <fstream>
#include "Color.h"
#include <cmath>
using namespace std;

Raster::Raster(){
    this -> width = 0;
    this -> height = 0;
    this -> pixels = NULL;
}

Raster::Raster(int pWidth, int pHeight, Color pFillColor){
    this -> width = pWidth;
    this -> height = pHeight;
    
    int size = pWidth * pHeight;
    this -> pixels = new Color[size];

    for(int i = 0; i < size; i++){
        pixels[i] = pFillColor;
    }
}

Raster::~Raster(){
    delete[] pixels;
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
            MyFile << index.red * 255 << " " << index.green * 255 << " " << index.blue * 255 << " ";
        }
        MyFile << endl;
    }

    MyFile.close();
}

void Raster::swap(float& x1, float& y1, float& x2, float& y2){
    if(x1 < x2){
        return;
    }
    else{
        float a = x1;
        float b = y1;
        x1 = x2;
        y1 = y2;
        x2 = a;
        y2 = b;
    }
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

    swap(x1, y1, x2, y2);

    //checking with slope
    if(abs(m) <= 1){
        float y = y1;
        for(int x = x1; x <= x2; x++ ){
            setColorPixel(x, round(y), fillColor);
            y+= m;
        }
    }else{
        m = (x2-x1)/(y2-y1);
        float x = x2;
        for(int y = y2; y>=y1; y--){
            setColorPixel(round(x), y, fillColor);
            x-=m;
        }
    }

}