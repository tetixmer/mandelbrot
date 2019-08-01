#ifndef ZOOM_H
#define ZOOM_H

#include <boost/multiprecision/cpp_dec_float.hpp> // for high-precision arithmetic

namespace tmcvsp {

struct Zoom {
    int x = 0;
    int y = 0;
    double scale = 0.0;

    Zoom(int x, int y, boost::multiprecision::cpp_dec_float_50 scale) : x(x), y(y), scale(scale) {}
};

}

#endif // ZOOM_H
