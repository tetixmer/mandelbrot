#include "colors.h"

namespace tmcvsp {

RGB::RGB(double r, double g, double b) : r(r), g(g), b(b) {

}

RGB RGB::operator-(const RGB& second) {
    return RGB(this->r-second.r, this->g-second.g, this->b-second.b);
}

/*HSV RGB::convertToHSV()
{
    hsv         out;
    double      min, max, delta;

    min = in.r < in.g ? in.r : in.g;
    min = min  < in.b ? min  : in.b;

    max = in.r > in.g ? in.r : in.g;
    max = max  > in.b ? max  : in.b;

    out.v = max;                                // v
    delta = max - min;
    if (delta < 0.00001)
    {
        out.s = 0;
        out.h = 0; // undefined, maybe nan?
        return out;
    }
    if( max > 0.0 ) { // NOTE: if Max is == 0, this divide would cause a crash
        out.s = (delta / max);                  // s
    } else {
        // if max is 0, then r = g = b = 0
        // s = 0, h is undefined
        out.s = 0.0;
        out.h = NAN;                            // its now undefined
        return out;
    }
    if( in.r >= max )                           // > is bogus, just keeps compilor happy
        out.h = ( in.g - in.b ) / delta;        // between yellow & magenta
    else
    if( in.g >= max )
        out.h = 2.0 + ( in.b - in.r ) / delta;  // between cyan & yellow
    else
        out.h = 4.0 + ( in.r - in.g ) / delta;  // between magenta & cyan

    out.h *= 60.0;                              // degrees

    if( out.h < 0.0 )
        out.h += 360.0;

    return out;
}*/




HSV::HSV(double h, double s, double v) : h(h), s(s), v(v) {

}

/*RGB HSV::convertToRGB() {
    //void HSVtoRGB(float& fR, float& fG, float& fB, float& fH, float& fS, float& fV) {

    RGB out(5.0, 2.0, 1.0);

    float fC = v * s; // Chroma
    float fHPrime = fmod(h / 60.0, 6);
    float fX = fC * (1 - fabs(fmod(fHPrime, 2) - 1));
    float fM = v - fC;

    if(0 <= fHPrime && fHPrime < 1) {
        out.r = fC;
        out.g = fX;
        out.b = 0;
    } else if(1 <= fHPrime && fHPrime < 2) {
        out.r = fX;
        out.g = fC;
        out.b = 0;
    } else if(2 <= fHPrime && fHPrime < 3) {
        out.r = 0;
        out.g = fC;
        out.b = fX;
    } else if(3 <= fHPrime && fHPrime < 4) {
        out.r = 0;
        out.g = fX;
        out.b = fC;
    } else if(4 <= fHPrime && fHPrime < 5) {
        out.r = fX;
        out.g = 0;
        out.b = fC;
    } else if(5 <= fHPrime && fHPrime < 6) {
        out.r = fC;
        out.g = 0;
        out.b = fX;
    } else {
        out.r = 0;
        out.g = 0;
        out.b = 0;
    }

    out.r += fM;
    out.g += fM;
    out.g += fM;

    return out;
    // }
}*/

RGB HSV::convertToRGB() {
    double      hh, p, q, t, ff;
    long        i;
    RGB         out(0.0, 0.0, 0.0);

    if(s <= 0.0) {       // < is bogus, just shuts up warnings
        out.r = v;
        out.g = v;
        out.b = v;
        return out;
    }
    hh = h;
    if(hh >= 360.0) hh = 0.0;
    hh /= 60.0;
    i = (long)hh;
    ff = hh - i;
    p = v * (1.0 - s);
    q = v * (1.0 - (s * ff));
    t = v * (1.0 - (s * (1.0 - ff)));

    switch(i) {
    case 0:
        out.r = v;
        out.g = t;
        out.b = p;
        break;
    case 1:
        out.r = q;
        out.g = v;
        out.b = p;
        break;
    case 2:
        out.r = p;
        out.g = v;
        out.b = t;
        break;

    case 3:
        out.r = p;
        out.g = q;
        out.b = v;
        break;
    case 4:
        out.r = t;
        out.g = p;
        out.b = v;
        break;
    case 5:
    default:
        out.r = v;
        out.g = p;
        out.b = q;
        break;
    }
    return out;
}

}
