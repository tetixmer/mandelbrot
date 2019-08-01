#include "GUI.h"
#include <QApplication>
#include <iostream>

//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc.hpp>

// a) Look at zoom functionality at begginer's level
// b) draw on SDL and be able to click
// c) start drawing with low number of iterations
// d) valgrind + profiler
// e) improve coloring
// f) improve speed
// g) check high amount of pixeling

// h) effect of inflections / Julia morphings

//namespace constants {
//extern const int WIDTH = 800;
//extern const int HEIGHT = 600;
//}

/*int getClosestXCoord(double coordX) {

    int minIdx = 0;
    double minPixelDiff = 99999.9;

    double coordLoopX = m_xCenter - constants::WIDTH/2*m_scale;


    for (int i=0; i<constants::WIDTH; i++) {
        coordLoopX += m_scale;
        if ( abs(coordLoopX - coordX) < min) {
            minPixelDiff = abs(coordLoopX - coordX);
            minIdx = i;
        }
    }

    return minIdx;
}*/





int main(int argc, char **argv)
{


    QApplication app(argc, argv);

    VerticalBox window;

    window.resize(240, 230);
    window.setWindowTitle("VerticalBox");    
    window.setWindowIcon(QIcon("mandelbrot_icon.png"));
    window.show();

    return app.exec();



























    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // SDL AREA THAT IS BEING REMOVED //////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////



    /*
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL init failed." << std::endl;
        return 1;
    }

    std::cout << "SDL init succeeded." << std::endl;

    SDL_Window* window = SDL_CreateWindow("Mandelbrot with SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, constants::WIDTH, constants::HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        SDL_Quit();
        return 2;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, constants::WIDTH, constants::HEIGHT);

    if (renderer == NULL) {
        std::cout << "Could not create renderer" << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }

    if (texture == NULL) {
        std::cout << "Could not create texture" << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }

    Uint32* buffer = new Uint32[constants::WIDTH*constants::HEIGHT];

    memset(buffer, 0x00, constants::WIDTH*constants::HEIGHT*sizeof(Uint32));


    //Uint8 temp = fractalCreator.m_arrayRGBA[5][215];
    //std::cout << fractalCreator.m_arrayRGBA[5][215][3] << std::endl;
    //fractalCreator.m_arrayRGBA[5][215][3] = 'A';
    //std::cout << fractalCreator.m_arrayRGBA[5][215][3] << std::endl;
    //fractalCreator.drawOnWindow();





    bool isRunning = true;

    SDL_Event event;

    int frame = 0;
    while (isRunning) {

        // "Compute" a frame of the fractal

        if (frame < TOTAL_FRAMES) {

            std::cout << "Computation of frame no: " << frame << std::endl;
            std::cout << "---------------------------------" << std::endl;

            fractalCreator.calculateIterationsForAllPixels("double");
            fractalCreator.calculateTotalIterations();
            fractalCreator.calculateCumulativeHues();
            fractalCreator.calculateRangeTotals();

            fractalCreator.drawFractal("HSV_with_histogram");


            // SDL Related
            fractalCreator.writeToSDLBuffer(buffer);


            // End of loop and prepare for next frame
            fractalCreator.prepareForTheNextFrame();


            SDL_UpdateTexture(texture, NULL, buffer, constants::WIDTH*sizeof(Uint32));
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture, NULL, NULL);
            SDL_RenderPresent(renderer);


            // Write to Bitmap file
            fractalCreator.writeBitmap("test"+ std::to_string(frame) + ".bmp");

            frame++;
        }

        // Zoom in



        // Stop after the first frame for now
        //isRunning = false;


        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
            else if (event.type == SDL_MOUSEBUTTONUP) {
                if (event.button.button == SDL_BUTTON_LEFT) {

                    double iterations = fractalCreator.m_fractal[event.button.y*constants::WIDTH + event.button.x];


                    int range = fractalCreator.getRange(std::round(iterations));
                    int rangeTotal = fractalCreator.m_rangeTotals[range];




                    double hue = (double)( 360.0* ( fractalCreator.m_histogramCumulative[std::floor(iterations)] + (iterations - std::floor(iterations))*( fractalCreator.m_histogramCumulative[std::ceil(iterations)] - fractalCreator.m_histogramCumulative[std::floor(iterations)] ) )/rangeTotal );

                    double hueCumulative = fractalCreator.m_huesCumulative[event.button.y*constants::WIDTH + event.button.x];

                    std::cout << event.button.x << " " << event.button.y << " Hue=" << hue << " Iters=" << iterations << " Hue cumulative rank=" << hueCumulative << std::endl;
                }
            }
        }

    }


    delete [] buffer;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);
    SDL_Quit();

    /*SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
                "SDL2Test",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                640,
                480,
                0
                );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();

    */



    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // SDL AREA THAT IS BEING REMOVED //////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////






    std::cout << "Finished." << std::endl;
    return 0;
}
