#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <complex>
#include <cmath>
#include <iostream>

namespace tmcvsp {

class Mandelbrot {
public:
    static const int MAX_ITERATIONS = 1000;

public:
    Mandelbrot();
    //static int getIterations(double x, double y);
    static double getIterations(double x, double y, const std::string& mode);
};

}

#endif // MANDELBROT_H
