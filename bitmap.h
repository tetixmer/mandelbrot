#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <cstdint>
#include <memory>

namespace tmcvsp {

class Bitmap {
private:
    int m_width{0};
    int m_height{0};
    std::unique_ptr<uint8_t[]> m_pPixels{nullptr};

public:
    Bitmap(int width, int height);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    bool write(std::string filename);
};

}

#endif // BITMAP_H
