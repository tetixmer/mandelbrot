#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include <iostream>
#include <vector>
#include <cmath> // for std::abs
#include "zoom.h"
#include "globals.h"

namespace tmcvsp {

class ZoomList {
private:
    double m_xCenter = 0.0; // -1.479796270901760024425;
    double m_yCenter = 0.0; // +0.001199443952813447746;
    double m_scale = 1.00; // 0.01*5*0.0001; //*std::pow(0.75,110);

    std::vector<Zoom> zooms;

public:
    ZoomList();
    //Zoomlist(double x, double y, double scale);
    void add(const Zoom& zoom);
    std::pair<double, double> doZoom(int x, int y);
    void setTo(double x, double y, double scale);
    std::pair<int, int> computeNextCoords();
};

}

#endif // ZOOMLIST_H
