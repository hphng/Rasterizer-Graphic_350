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