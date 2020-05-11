#include<windows.h>
#include<iostream>
#include<ShellscalingApi.h>
#include<shtypes.h>
#include <cmath>

using namespace std;

#define PI 3.14

int main()
{

    if (SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE)) {

    }
    /*if (SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE)) {

    }*/
    //Get a console handle
    HWND myconsole = GetConsoleWindow();
    //Get a handle to device context
    HDC console = GetDC(myconsole);

    //int pixel = 0;

    ////Choose any color
    //COLORREF COLOR = RGB(255, 255, 255);

    ////Draw pixels
    //for (double i = 0; i < PI * 4; i += 0.05)
    //{
    //    SetPixel(mydc, pixel, (int)(50 + 25 * cos(i)), COLOR);
    //    pixel += 1;
    //}

    POINT p;
    HMONITOR monitor;
    DEVICE_SCALE_FACTOR pScale = DEVICE_SCALE_FACTOR::SCALE_100_PERCENT;
    int scalefc;
    HRESULT err2;
    auto err = GetLastError();
    COLORREF pixelColor;
    HDC mydc = GetDC(NULL);
    int pixel = 0;
    int x, y;
    double i = 0;
    while (true) {

        
        if (GetPhysicalCursorPos(&p))
        {
            //cout << "cursor position: ( "<< p.x << ","<< p.y<< ")" << endl;
            monitor = MonitorFromPoint(p, MONITOR_DEFAULTTONEAREST);
            err2 = GetScaleFactorForMonitor(monitor, &pScale);
            scalefc = 100; //static_cast<int>(pScale);
            x = p.x * (double)(scalefc / 100);
            y = p.y * (double)(scalefc / 100);

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