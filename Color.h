#ifndef COLOR_H
#define COLOR_H

#define Red Color(1.0, 0.0, 0.0)
#define Green Color(0.0, 1.0, 0.0)
#define Blue Color(0.0, 0.0, 1.0)
#define Black Color(0.0, 0.0, 0.0)
#define White Color(1.0, 1.0, 1.0)

struct Color {
    float red;
    float green;
    float blue;

    Color();
    Color(float pRed, float pGreen, float pBlue);

    void clamp();
    Color operator+(Color c);
    Color operator-(Color c);
    Color operator*(const float scalar);

    void printColor();
};

#endif