#include<windows.h>
#include<iostream>
#include<ShellscalingApi.h>
#include<shtypes.h>
#include <cmath>

using namespace std;

#define PI 3.14

int main()
{

    if (!SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE)) {
        //set process dpi aware
        //if failed exit
        return 0;
    }

    //Get a console handle
    HWND myconsole = GetConsoleWindow();
    //Get a handle to device context
    HDC console = GetDC(myconsole);

    POINT p;
    auto err = GetLastError();
    COLORREF pixelColor;
    HDC mydc = GetDC(NULL);
    int pixel = 0;
    int x, y;
    double i = 0;
    while (true) {
        
        if (GetPhysicalCursorPos(&p))
        {
            x = p.x; 
            y = p.y; 

            pixelColor = GetPixel(mydc, x, y);
            //cout << "color at pixel: " << pixelColor << endl;

            SetPixel(console, pixel, (int)(50 + 25 * cos(i)), pixelColor);
            SetPixel(console, pixel, (int)(49 + 25 * cos(i)), pixelColor);
            SetPixel(console, pixel, (int)(48 + 25 * cos(i)), pixelColor);
            SetPixel(console, pixel, (int)(47 + 25 * cos(i)), pixelColor);
            SetPixel(console, pixel, (int)(46 + 25 * cos(i)), pixelColor);
            SetPixel(console, pixel, (int)(45 + 25 * cos(i)), pixelColor);
            pixel += 1;
            i += 0.05;
        }
        else {
            err = GetLastError();
        }
    }

    /*ReleaseDC(myconsole, mydc);
    cin.ignore();*/

    return 0;
}