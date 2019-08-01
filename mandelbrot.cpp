#include "mandelbrot.h"

namespace tmcvsp {

Mandelbrot::Mandelbrot() {

}

/*int Mandelbrot::getIterations(double x, double y) {

    std::complex<double> z = 0.0;
    std::complex<double> c(x, y);

    int iterations = 0;

    while ( (abs(z) <= 2) && (iterations < Mandelbrot::MAX_ITERATIONS) ) {
        z = z*z + c;
        iterations++;
    }

    return iterations;

}*/

double Mandelbrot::getIterations(double x, double y, const std::string& mode) {

    std::complex<double> z = 0.0;
    std::complex<double> c(x, y);

    int iterations = 0;

    while ( (abs(z) <= 2) && (iterations < Mandelbrot::MAX_ITERATIONS) ) {
        z = z*z + c;
        iterations++;
    }

    //std::cout << "TEST" << z << " " << iterations << std::endl;

    if (mode == "int") {
        return iterations;
    }
    else if (mode == "double") {

        if (iterations == Mandelbrot::MAX_ITERATIONS) {
            //std::cout << "TEST" << std::endl;
            return iterations;            
        }

        //if ( std::log(std::log2(abs(z))) < 1.0 ) {
            //std::cout << "This pixel has: " << std::log(std::log2(abs(z))) << std::endl;
        //}

        //if ( iterations + 1 - std::log(std::log2(abs(z))) < 0 ) {
        //    return 0;
        //}
        //else {
            return iterations + 1 - std::log(std::log2(abs(z)));
        //}

    }



}


}
