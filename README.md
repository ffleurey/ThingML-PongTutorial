This repo contains a set of ThingML examples targtting multiple platforms.

## Posix C / SDL 2

The posix version uses the SDL2 library and SDL2_TTF to draw text.

Install the required libraries with:

`sudo apt-get install libsdl2-dev libsdl2-ttf-dev`

## Arduino / Adafruit ST7735

For the arduino target, we are using this shield: https://www.adafruit.com/products/802

This requires the installation of the corresponding libraries in the arduino IDE. The 2 libraries to install are:

* https://github.com/adafruit/Adafruit-ST7735-Library 
* https://github.com/adafruit/Adafruit-GFX-Library 

More details on how to connect and install the libraries can be found here: https://learn.adafruit.com/adafruit-shield-compatibility/1-dot-8-tft-shield-w-slash-joystick

Make sure your hardware and Arduino IDE is working before trying to compile the ThingML generated code.