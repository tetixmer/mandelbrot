#include "fractalcreator.h"

//int tmcvsp::FractalCreator::constants::WIDTH = 800;
//int tmcvsp::FractalCreator::constants::HEIGHT = 600;

namespace tmcvsp {

FractalCreator::FractalCreator() : m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
    m_histogramCumulative(new int[Mandelbrot::MAX_ITERATIONS]{0}),
    m_huesCumulative(new int[constants::WIDTH*constants::HEIGHT]{0}),
    m_fractal(new double[constants::WIDTH*constants::HEIGHT]{0.0}),
    m_bitmap(constants::WIDTH, constants::HEIGHT),
    m_zoomList() {

    // you could copy data from constructor arguments to internal variables here.

    m_arrayRGBA.assign( constants::HEIGHT, std::vector<std::vector<uint8_t>>( constants::WIDTH, std::vector<uint8_t>(4, 0x00) ) );

    //m_zoomList.add(Zoom(constants::WIDTH/2, constants::HEIGHT/2, 4.0/constants::WIDTH));

    std::cout << "Created a fractal." << std::endl;
}

FractalCreator::FractalCreator(double xLoc, double yLoc, double scale, double scaleFactor) : m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
    m_histogramCumulative(new int[Mandelbrot::MAX_ITERATIONS]{0}),
    m_huesCumulative(new int[constants::WIDTH*constants::HEIGHT]{0}),
    m_fractal(new double[constants::WIDTH*constants::HEIGHT]{0.0}),
    m_bitmap(constants::WIDTH, constants::HEIGHT),
    m_zoomList() {

    // you could copy data from constructor arguments to internal variables here.

    m_arrayRGBA.assign( constants::HEIGHT, std::vector<std::vector<uint8_t>>( constants::WIDTH, std::vector<uint8_t>(4, 0x00) ) );

    m_zoomList.setTo( xLoc, yLoc, scale );
    m_scaleFactor = scaleFactor;
    //m_zoomList.add(Zoom(constants::WIDTH/2, constants::HEIGHT/2, 4.0/constants::WIDTH));

    std::cout << "Created a fractal." << std::endl;
}

FractalCreator::~FractalCreator() {
    std::cout << "Worker thread: Worker destroyed." << std::endl;
    // free resources
}






// --- PROCESS ---
// Start processing data.
void FractalCreator::process() {
    // allocate resources using new here

    std::cout << "LET'S SEE IF EMIT WORKS HERE" << std::endl;


    addRange(0.0, tmcvsp::RGB(0, 0, 0));
    //fractalCreator.addRange(0.3, tmcvsp::RGB(255, 0, 0));
    //fractalCreator.addRange(0.5, tmcvsp::RGB(255, 255, 0));
    addRange(1.0, tmcvsp::RGB(0.9, 0, 0));





    //fractalCreator.addZoom(tmcvsp::Zoom(constants::WIDTH/2, constants::HEIGHT/2, 1.0));
    //fractalCreator.addZoom(tmcvsp::Zoom(312, 304, 0.1));



    //fractalCreator.addZoom(tmcvsp::Zoom( xLocText->text().toDouble() + constants::WIDTH/2,
    //                        -yLocText->text().toDouble() + constants::HEIGHT/2,
    //                        scaleText->text().toDouble() ));

    //    fractalCreator.calculateIteration();
    //    fractalCreator.calculateTotalIterations();
    //    fractalCreator.calculateRangeTotals();

    //    fractalCreator.drawFractal();

    //    fractalCreator.writeBitmap("test.bmp");


    //fractalCreator.run("test.bmp");






    uint32_t* buffer = new uint32_t[constants::WIDTH*constants::HEIGHT];

    memset(buffer, 0x00, constants::WIDTH*constants::HEIGHT*sizeof(uint32_t));


    //Uint8 temp = fractalCreator.m_arrayRGBA[5][215];
    //std::cout << fractalCreator.m_arrayRGBA[5][215][3] << std::endl;
    //fractalCreator.m_arrayRGBA[5][215][3] = 'A';
    //std::cout << fractalCreator.m_arrayRGBA[5][215][3] << std::endl;
    //fractalCreator.drawOnWindow();





    bool isRunning = true;

    int frame = 0;
    while (isRunning) {

        // "Compute" a frame of the fractal

        if (frame < globalvars::TOTAL_FRAMES) {

            std::cout << "Computation of frame no: " << frame << std::endl;
            std::cout << "---------------------------------" << std::endl;

            calculateIterationsForAllPixels("double");
            std::cout << "OKKKKKKA" << std::endl;
            calculateTotalIterations();
            std::cout << "OKKKKKKB" << std::endl;
            calculateCumulativeHues();
            std::cout << "OKKKKKKC" << std::endl;
            calculateRangeTotals();


            std::cout << "OKKKKKKD" << std::endl;

            drawFractal("HSV_with_histogram");


            // SDL Related
            writeToSDLBuffer(buffer);

            std::cout << "OKKKKKKE" << std::endl;

            // End of loop and prepare for next frame
            prepareForTheNextFrame(m_scaleFactor);


            //SDL_UpdateTexture(texture, NULL, buffer, constants::WIDTH*sizeof(Uint32));
            //SDL_RenderClear(renderer);
            //SDL_RenderCopy(renderer, texture, NULL, NULL);
            //SDL_RenderPresent(renderer);

            std::cout << "OKKKKKK2" << std::endl;
            // Write to Bitmap file
            writeBitmap("test"+ std::to_string(frame) + ".bmp");
            std::cout << "OKKKKKK3" << std::endl;
            frame++;



            std::cout << "Got the 500th element equal to: " << buffer[500] << std::endl;
            emit sendBuffer(buffer);




            while ( true ) {
                QAbstractEventDispatcher::instance(QThread::currentThread())->processEvents(QEventLoop::AllEvents);

                mutex.lock();

                if ( drawingCompleted ) {
                    drawingCompleted = false;
                    mutex.unlock();
                    break;
                }

                mutex.unlock();
            }





            QAbstractEventDispatcher::instance(QThread::currentThread())->processEvents(QEventLoop::AllEvents);

            mutex.lock();

            if ( terminationRequested ) {
                mutex.unlock();
                break;
            }

            //if (QThread::currentThread()->isInterruptionRequested()) {
            //    mutex.unlock();
            //    break;
            //}

            //std::cout << " HI" << std::endl;


            mutex.unlock();






        }
        else {
            isRunning = false;
        }



    }


    std::cout << "OKKKKKK7" << std::endl;

    delete [] buffer;

    std::cout << "OKKKKKK8" << std::endl;


    emit reenableButtons();

    // Uncomment this so that thread+worker can be destroyed. Not used atm
    //emit finished();
}

void FractalCreator::setDrawingFlag() {
    QMutexLocker locker(&mutex);
    drawingCompleted = true;
    std::cout << "Worker thread: Drawing flag set successfully." << std::endl;
}

void FractalCreator::setTerminationFlag() {
    QMutexLocker locker(&mutex);
    terminationRequested = true;
    std::cout << "Worker thread: Termination flag set successfully." << std::endl;
}



void FractalCreator::addRange(double endPercentage, const RGB& rgb) {
    m_ranges.push_back(endPercentage*Mandelbrot::MAX_ITERATIONS);
    m_colors.push_back(rgb);

    if (m_bGotFirstRange) {
        m_rangeTotals.push_back(0);
    }

    m_bGotFirstRange = true;

}

void FractalCreator::addZoom(const Zoom& zoom) {
    m_zoomList.add(zoom);
}

/*void FractalCreator::run(const std::string& filename) {

    calculateIteration();
    calculateTotalIterations();
    calculateRangeTotals();

    drawFractal();

    writeBitmap(filename);

}*/

void FractalCreator::computeNextZoom() {


}



void FractalCreator::calculateIterationsForAllPixels(const std::string& mode) {

    //std::cout << "Here is the closest coord: " << m_zoomList.computeNextCoords(1.55) << std::endl;


    // Resetting m_histogram, so that increments ++ will always work
    m_histogram.reset(new int[Mandelbrot::MAX_ITERATIONS]{0});
    //memset(m_histogram, 0, Mandelbrot::MAX_ITERATIONS);

    // Debug only - should give no output
    for (int i=0; i<Mandelbrot::MAX_ITERATIONS; i++) {
        if ( m_histogram[i] != 0 ) {
            std::cout << "i=" << m_histogram[i] << std::endl;
        }
    }



    for (int y=0; y<constants::HEIGHT; y++) {
        for (int x=0; x<constants::WIDTH; x++) {

            std::pair<double, double> coords = m_zoomList.doZoom(x, y);

            if ( x==0 && y==0 ) {
                std::cout << "HEREEEEE" << x << y << coords.first << " " << coords.second << std::endl;

                std::complex<double> c(coords.first, coords.second);

                std::cout << abs(c) << std::endl;
                std::cout << std::log2(abs(c)) << std::endl;
                std::cout << std::log(std::log2(abs(c))) << std::endl;


            }

            if (mode == "int") {
                int iterations = std::round( Mandelbrot::getIterations(coords.first, coords.second, "double") );
                m_fractal[y*constants::WIDTH + x] = iterations;

                if (iterations != Mandelbrot::MAX_ITERATIONS) {
                    m_histogram[iterations]++;
                }
            }
            else if (mode == "double") {
                double iterations = Mandelbrot::getIterations(coords.first, coords.second, "double");
                m_fractal[y*constants::WIDTH + x] = iterations;


                // std::cout << "x: " << x << " y: " << y << " number of iterations: " << iterations << std::endl;

                if (std::round(iterations) != Mandelbrot::MAX_ITERATIONS) {

                    /////////////////////////////////////
                    // CAREFUL HERE
                    // VALGRIND 1ST HIT, HAD TO "CORRECT"
                    /////////////////////////////////////


                    if ( std::floor(iterations) >= 0 ) {
                        m_histogram[std::floor(iterations)]++;
                    }
                    else {
                        m_histogram[0]++;
                    }


                }
            }





        }

        // Simple Progress bar
        //std::cout << 100.0*y/constants::HEIGHT << "%" << '\r' << std::flush;
    }

}

void FractalCreator::calculateTotalIterations() {

    for (int i=0; i<Mandelbrot::MAX_ITERATIONS; i++) {
        std::cout << m_histogram[i] << " " << std::flush;
        m_total += m_histogram[i];

        if (i>0) {
            m_histogramCumulative[i] = m_histogramCumulative[i-1] + m_histogram[i];
            //std::cout << m_histogramCumulative[i] << " " << std::flush;
        }
        else { // if ( i==0 )
            m_histogramCumulative[i] = m_histogram[i];
        }

    }

}

/*void FractalCreator::calculateCumulativeHues() {

    for (int y=0; y<constants::HEIGHT; y++) {
        for (int x=0; x<constants::WIDTH; x++) {

            double iterations = m_fractal[y*constants::WIDTH + x];

            int count = 0;
            if ( std::round(iterations) != Mandelbrot::MAX_ITERATIONS ) {
                for (int i=0; i<constants::WIDTH*constants::HEIGHT; i++) {
                    if ( iterations > m_fractal[i] ) {
                        count++;
                    }
                }
            }

            m_huesCumulative[y*constants::WIDTH + x] = count;



        }
        std::cout << y << std::endl;
    }

}*/

void FractalCreator::calculateCumulativeHues() {

    //double* fractalValues = fractalCreator.m_fractal.get();

    //std::vector<int> idx(constants::WIDTH*constants::HEIGHT);

    std::unique_ptr<int[]> temp_sorted_idxs(new int[constants::WIDTH*constants::HEIGHT]{0});
    std::iota(&temp_sorted_idxs[0], &temp_sorted_idxs[constants::WIDTH*constants::HEIGHT], 0);


    for (int i=0; i<100; i++) {
        // std::cout << m_fractal[i] << " " << temp_sorted_idxs[i] << std::endl;
    }




    //std::sort(&fractalValues[0], &fractalValues[5]);
    std::sort(&temp_sorted_idxs[0], &temp_sorted_idxs[constants::WIDTH*constants::HEIGHT],
            [this](int i1, int i2) {return m_fractal[i1] < m_fractal[i2];});

    //[&fractalValues](size_t i1, size_t i2) {return fractalValues[i1] < fractalValues[i2];});


    for (int i=0; i<100; i++) {
        // std::cout << m_fractal[i] << " " << temp_sorted_idxs[i] << std::endl;
    }




    std::iota(&m_huesCumulative[0], &m_huesCumulative[constants::WIDTH*constants::HEIGHT], 0);


    std::sort(&m_huesCumulative[0], &m_huesCumulative[constants::WIDTH*constants::HEIGHT],
            [&temp_sorted_idxs](int i1, int i2) {return temp_sorted_idxs[i1] < temp_sorted_idxs[i2];});



    for (int i=0; i<620; i++) {
        // std::cout << "CHECK THIS: " << m_fractal[i] << " " << m_huesCumulative[i] << std::endl;
    }




}

void FractalCreator::calculateRangeTotals() {

    // Reset m_rangeTotals to zero
    for (int i=0; i<m_rangeTotals.size(); i++) {
        m_rangeTotals[i] = 0;
    }

    int index = 0;

    for (int i=0; i<Mandelbrot::MAX_ITERATIONS; i++) {
        int pixels = m_histogram[i];

        if (i >= m_ranges[index+1]) {
            index++;
        }

        m_rangeTotals[index] += pixels;
    }



    for (int value : m_rangeTotals) {
        std::cout << "Range total: " << value << std::endl;
    }
}

int FractalCreator::getRange(int iterations) const {

    int range = 0;

    for (int i=0; i<m_ranges.size(); i++) {

        range = i;

        if (iterations < m_ranges[i]) {
            break;
        }
    }

    range--;

    assert(range > -1);
    assert(range < m_ranges.size());

    return range;

}


void FractalCreator::drawFractal(const std::string& mode) {

    //RGB startColor(0, 0, 0);
    //RGB endColor(0, 0, 255);
    //RGB colorDiff = endColor - startColor;

    for (int y=0; y<constants::HEIGHT; y++) {
        for (int x=0; x<constants::WIDTH; x++) {

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;


            if (mode == "ranges") {

                int iterations = std::round(m_fractal[y*constants::WIDTH + x]);

                int range = getRange(iterations);
                int rangeTotal = m_rangeTotals[range];
                int rangeStart = m_ranges[range];

                RGB& startColor = m_colors[range];
                RGB& endColor = m_colors[range+1];
                RGB colorDiff = endColor - startColor;


                if (iterations != Mandelbrot::MAX_ITERATIONS) {
                    double hue = 0.0;
                    for (int i=rangeStart; i<iterations; i++) {
                        hue += (double)(m_histogram[i])/rangeTotal;
                    }

                    //green = pow(255,hue);

                    red = startColor.r + colorDiff.r*hue;
                    green = startColor.g + colorDiff.g*hue;
                    blue = startColor.b + colorDiff.b*hue;
                    //green = hue*255;
                }

            }
            else if (mode == "HSV_normal") {

                double iterations = m_fractal[y*constants::WIDTH + x];

                int range = getRange(std::round(iterations));
                int rangeTotal = m_rangeTotals[range];
                int rangeStart = m_ranges[range];

                double hue = 360.0*iterations/Mandelbrot::MAX_ITERATIONS;
                //if (std::round(iterations) != Mandelbrot::MAX_ITERATIONS) {
                //    hue = (int)( 360.0* ( m_histogramCumulative[std::floor(iterations)] + (iterations - std::floor(iterations))*( m_histogramCumulative[std::ceil(iterations)] - m_histogramCumulative[std::floor(iterations)] ) )/rangeTotal );
                //    //hue *= 255;
                //    hue = 360 - hue;
                //}
                double saturation = 1.0;
                double value = iterations < Mandelbrot::MAX_ITERATIONS ? 1.0 : 0.0;


                HSV hsv_color(hue, saturation, value);

                RGB rgb_color = hsv_color.convertToRGB();
                red = (uint8_t)(rgb_color.r*255);
                green = (uint8_t)(rgb_color.g*255);
                blue = (uint8_t)(rgb_color.b*255);
            }

            else if (mode == "HSV_with_histogram") {

                double iterations = m_fractal[y*constants::WIDTH + x];

                int range = getRange(std::round(iterations));
                int rangeTotal = m_rangeTotals[range];
                int rangeStart = m_ranges[range];


                double hue = 0.0;
                if(std::round(iterations) != Mandelbrot::MAX_ITERATIONS) {


                    /////////////////////////////////////
                    // CAREFUL HERE
                    // VALGRIND 2ND HIT, HAD TO "CORRECT"/COMMENT OUT
                    // (NO EFFECT ANYWAY BECAUSE hue IS REDEFINED BELOW
                    /////////////////////////////////////


                    //hue = (double)( 360.0* ( m_histogramCumulative[std::floor(iterations)] + (iterations - std::floor(iterations))*( m_histogramCumulative[std::ceil(iterations)] - m_histogramCumulative[std::floor(iterations)] ) )/rangeTotal );
                    //hue = 360 - hue;
                }

                hue = 360.0*m_huesCumulative[y*constants::WIDTH + x]/rangeTotal;

                if (x==1109 && y==412) {
                    std::cout << "hue=" << hue << " " << (int)red << " " << (int)green << " " << (int)blue << std::endl;
                }


                double saturation = 1.0;
                double value = iterations < Mandelbrot::MAX_ITERATIONS ? 1.0 : 0.0;

                //if (std::round(iterations) != Mandelbrot::MAX_ITERATIONS) {
                //    for (int i=rangeStart; i<iterations; i++) {
                //        hue += (double)(m_histogram[i])/rangeTotal;
                //    }
                //}

                HSV hsv_color(hue, saturation, value);

                RGB rgb_color = hsv_color.convertToRGB();
                red = (uint8_t)(rgb_color.r*255);
                green = (uint8_t)(rgb_color.g*255);
                blue = (uint8_t)(rgb_color.b*255);

                if (x==400 && y==300) {
                    std::cout << "hue=" << hue << " " << (int)red << " " << (int)green << " " << (int)blue << std::endl;
                }

            }



            m_arrayFixedRGBA[y][x][0] = red;
            m_arrayFixedRGBA[y][x][1] = green;
            m_arrayFixedRGBA[y][x][2] = blue;
            m_arrayFixedRGBA[y][x][3] = 0xFF;

            m_bitmap.setPixel(x, y, red, green, blue);

        }
    }

}

void FractalCreator::writeToSDLBuffer(uint32_t* buffer) {
    //std::cout << "THIS must be equal to: " << buffer[500] << std::endl;

    for (int y=0; y<constants::HEIGHT; y++) {
        for (int x=0; x<constants::WIDTH; x++) {

            uint32_t color = 0;

            uint8_t red = m_arrayFixedRGBA[y][x][0];
            uint8_t green = m_arrayFixedRGBA[y][x][1];
            uint8_t blue = m_arrayFixedRGBA[y][x][2];


            color += 0xFF;
            color <<= 8;
            color += red;
            color <<= 8;
            color += green;
            color <<= 8;
            color += blue;


            //if (y==240) {
            //    std::cout << std::hex << x << ", " << y << ", " << color << std::endl;
            //}


            buffer[y*constants::WIDTH + x] = color;

            //if (x==241 && y==240) {
            //    std::cout << std::hex << x << ", " << y << ", " << buffer[y*constants::WIDTH + x] << std::endl;
            //}


        }
    }

}

void FractalCreator::writeBitmap(const std::string& filename) {
    m_bitmap.write(filename);
}

void FractalCreator::prepareForTheNextFrame(double scaleFactor) {
    std::pair<int, int> nextCoords = m_zoomList.computeNextCoords();


    std::cout << "next coords were computed as: " << nextCoords.first << ", " << nextCoords.second << std::endl;

    m_zoomList.add(Zoom(nextCoords.first, nextCoords.second, scaleFactor));


}

}
