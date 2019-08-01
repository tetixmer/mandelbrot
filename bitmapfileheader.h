#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include <cstdint> // to use 32 bit integers

#pragma pack(2) // so that numbers are not padded behind the scenes

namespace tmcvsp {

struct BitmapFileHeader {
    char header[2]{'B', 'M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
};

}

#endif // BITMAPFILEHEADER_H
