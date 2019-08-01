#ifndef RGB_H
#define RGB_H

#include <cmath>

namespace tmcvsp {

struct RGB {
    double r;
    double g;
    double b;

    RGB(double r, double g, double b);
    RGB operator-(const RGB& second);
    //HSV convertToHSV();
};

struct HSV {
    double h;       // angle in degrees
    double s;       // a fraction between 0 and 1
    double v;       // a fraction between 0 and 1

    HSV(double h, double s, double v);
    RGB convertToRGB();
};

}

#endif // RGB_H
