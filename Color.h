struct Color {
    float red;
    float green;
    float blue;

    Color();
    Color(float pRed, float pGreen, float pBlue);

    void clamp();
};