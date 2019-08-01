#include "zoomlist.h"

namespace tmcvsp {

ZoomList::ZoomList() {

}

//ZoomList::ZoomList(double x, double y, double scale) : m_xCenter(x), m_yCenter(y), m_scale(scale) {
//
//}



void ZoomList::add(const Zoom& zoom) {
    zooms.push_back(zoom);

    m_xCenter += (zoom.x - constants::WIDTH/2)*m_scale;
    m_yCenter += -(zoom.y - constants::HEIGHT/2)*m_scale;

    m_scale *= zoom.scale;

    std::cout << m_xCenter << ", " << m_yCenter << ", " << m_scale << std::endl;
}

std::pair<double, double> ZoomList::doZoom(int x, int y) {

    double xFractal = (x - constants::WIDTH/2)*m_scale + m_xCenter;
    double yFractal = -(y - constants::HEIGHT/2)*m_scale + m_yCenter;

    return std::pair<double, double>(xFractal, yFractal);
}

void ZoomList::setTo(double x, double y, double scale) {
    m_xCenter = x;
    m_yCenter = y;
    m_scale = scale;
}

std::pair<int, int> ZoomList::computeNextCoords() {

    std::cout << " IT IS HERE GLOBALLY: " << globalvars::targetXCoord << std::endl;
    std::cout << "m_xCenter is: " << m_xCenter << std::endl;

    int minX = -1;
    boost::multiprecision::cpp_dec_float_50 minPixelDiff = 99999.9;
    boost::multiprecision::cpp_dec_float_50 coordLoop = m_xCenter - constants::WIDTH/2*m_scale; // Left most coordX

    boost::multiprecision::cpp_dec_float_50 diffAbs;
    for (int i=0; i<constants::WIDTH; i++) {
        diffAbs = abs(coordLoop - globalvars::targetXCoord);
        if ( diffAbs < minPixelDiff) {
            minPixelDiff = diffAbs;
            minX = i;
        }
        coordLoop += m_scale;

    }

    int minY = -1;
    minPixelDiff = 99999.9;
    coordLoop = m_yCenter - constants::HEIGHT/2*m_scale; // Upper most coordY

    for (int i=0; i<constants::HEIGHT; i++) {
        diffAbs = abs(coordLoop - globalvars::targetYCoord);
        if ( diffAbs < minPixelDiff) {
            minPixelDiff = diffAbs;
            minY = i;
        }
        coordLoop += m_scale;

    }

    return std::pair<int, int>(minX, minY);

}




}

