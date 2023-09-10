#ifndef RASTER_H
#define RASTER_H

#include "Color.h"
class Raster
{
public:
    Raster();
    Raster(int pWidth, int pHeight, Color pFillColor);
    ~Raster();

    int getWidth();
    int getHeight();

    Color getColorPixel(int x, int y);
    void setColorPixel(int x, int y, Color pFillColor);
    void clear(Color pFillColor);

    void writeToPPM();

private:
    int width;
    int height;
    Color* pixels;
    
};

#endif