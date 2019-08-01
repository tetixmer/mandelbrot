#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <iostream>
#include <string>
#include <numeric> // for std::iota
#include <cstdint>
#include <memory>
#include <assert.h>
#include "globals.h"
#include "zoom.h"
#include "bitmap.h"
#include "mandelbrot.h"
#include "zoomlist.h"
#include "colors.h"
//#include <SDL.h>

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QAbstractEventDispatcher>

namespace tmcvsp {

class FractalCreator : public QObject {
    Q_OBJECT

public:
    std::unique_ptr<int[]> m_histogram;
    std::unique_ptr<int[]> m_histogramCumulative;
    std::unique_ptr<int[]> m_huesCumulative;
    std::unique_ptr<double[]> m_fractal;
    Bitmap m_bitmap;
    ZoomList m_zoomList;
    int m_total = 0;

    double m_scaleFactor = 1.0;

    std::vector<int> m_ranges;
    std::vector<RGB> m_colors;
    std::vector<int> m_rangeTotals;

    bool m_bGotFirstRange = false;

public:
    std::vector<std::vector<std::vector<uint8_t>>> m_arrayRGBA;

    std::array<std::array<std::array<uint8_t,4>, constants::WIDTH>, constants::HEIGHT> m_arrayFixedRGBA;

    FractalCreator();
    FractalCreator(double xLoc, double yLoc, double scale, double scaleFactor);
    ~FractalCreator();

    //void computeFractal();

    void addRange(double endPercentage, const RGB& rgb);
    void addZoom(const Zoom& zoom);
    //void run(const std::string& filename);

    void computeNextZoom();


    void calculateIterationsForAllPixels(const std::string& mode);
    void calculateTotalIterations();
    void calculateCumulativeHues();
    void calculateRangeTotals();
    int getRange(int iterations) const;
    void drawFractal(const std::string& mode);
    void writeToSDLBuffer(uint32_t* buffer);
    void writeBitmap(const std::string& filename);

    void prepareForTheNextFrame(double scale);

public slots:
    void process();
    void setDrawingFlag();
    void setTerminationFlag();

signals:
    void sendBuffer(uint32_t* bufferOfImage);
    void finished();
    void reenableButtons();


private:
    QMutex mutex;
    bool drawingCompleted = false;
    bool terminationRequested = false;

};

}

#endif // FRACTALCREATOR_H
