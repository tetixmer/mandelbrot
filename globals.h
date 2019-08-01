#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <boost/multiprecision/cpp_dec_float.hpp> // for high-precision arithmetic


namespace constants {
constexpr static int WIDTH = 600;
constexpr static int HEIGHT = 400;
//constexpr static int TOTAL_FRAMES = 10;
}

namespace globalvars {

extern boost::multiprecision::cpp_dec_float_50 targetXCoord;
extern boost::multiprecision::cpp_dec_float_50 targetYCoord;

extern int TOTAL_FRAMES;

}

#endif
