#ifndef MODULESHREBENIUK_H_INCLUDED
#define MODULESHREBENIUK_H_INCLUDED

#include <cmath>

using namespace std;

class ClassLab12_Hrebeniuk {
public:
    ClassLab12_Hrebeniuk(string color = "", string pattern = "", float height = 0.1, float radius = 0.1) {
        setColor(color);
        setPattern(pattern);
        setHeight(height);
        setRadius(radius);
    }

    string getColor() { return mColor; }
    string getPattern() { return mPattern; }
    float getHeight() { return mHeight; }
    float getRadius() { return mRadius; }
    float getVolume() { return (1.0/3 * M_PI * pow(mRadius, 2) * mHeight); }

    void setColor(string color);
    void setPattern(string pattern);
    void setHeight(float height);
    void setRadius(float radius);
private:
    string mColor;
    string mPattern;
    float mHeight;
    float mRadius;
};

void ClassLab12_Hrebeniuk::setColor(string color) {
    if (color.empty()) {
        color = "white";
    }

    mColor = color;
}

void ClassLab12_Hrebeniuk::setPattern(string pattern) {
    if (pattern.empty()) {
        pattern = "none";
    }

    mPattern = pattern;
}

void ClassLab12_Hrebeniuk::setHeight(float height) {
    if (height < 0.1) {
        height = 0.1;
    }

    mHeight = height;
}

void ClassLab12_Hrebeniuk::setRadius(float radius) {
    if (radius < 0.1) {
        radius = 0.1;
    }

    mRadius = radius;
}

#endif // MODULESHREBENIUK_H_INCLUDED
