#ifndef RASTER_H
#define RASTER_H

#include "Color.h"
#include "Triangle.h"
#include "Vector.h"
#include "Model.h"
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

    float getDepthPixel(int x, int y);
    void setDepthPixel(int x, int y, float depth);
    void clear(float depth);

    void swap(float &x1, float &y1, float &x2, float &y2);
    void swap_Interpolated(float &x1, float &y1, float &x2, float &y2, Color &color1, Color &color2);
    void drawLine_DDA(float x1, float y1, float x2, float y2, Color fillColor);
    void drawLine_DDA_Interpolated(float x1, float y1, float x2, float y2, Color color1, Color color2);

    void drawTriangle2D_DotProduct(Triangle2D tri);
    void drawTriangle3D_Barycentric(Triangle3D T3D);
    
    void drawModel(Model model);

private:
    int width;
    int height;
    Color* pixels;
    float* depthPixels;
};

#endif