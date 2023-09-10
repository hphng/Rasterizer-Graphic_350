#include "Raster.h"
#include <iostream>
#include <fstream>
#include "Color.h"
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

    int index = ( h-1 - y) * w + x;

    cout << "index is: " << index << endl; 

    pixels[index].red = pFillColor.red;
    pixels[index].green = pFillColor.green;
    pixels[index].blue = pFillColor.blue;

    pixels[index].printColor();
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

    ofstream MyFile("test.ppm");

    MyFile << "P3" << endl;
    MyFile << w << " " << h << endl;
    MyFile << "255" << endl;

    for(int j = h-1; j >= 0; j--){
        for(int i = 0; i < w; i++){
            Color index = getColorPixel(i, j);
            MyFile << index.red *255 << " " << index.green *255 << " " << index.blue *255 << " ";
        }
        MyFile << endl;
    }

    MyFile.close();

}