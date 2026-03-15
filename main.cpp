// This file acts as the main driver/library

//
//
// ILI9341 communicates to MCU via SCL, CSX, D/CX and SDI + SDO
// Due to missing SDI on block diagram, using SDA is likely the best option
//
// CSL: GPIO 5
// SDA: GPIO 3
// SDI: MOSI: 19
// SDO: MISO: 21

// CSX: CE0 / CE1: 24 / 26
// SCLK: 23
//

#include <iostream> // IO operations
#include <chrono>   // Time Utilities
#include <thread>   // For Pausing/Sleeping Purposes

#include <gpiod.h>

int main(int argc, char *argv[])
{
  std::cout << "Hello, World!" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "Slept for 500 ms!" << std::endl;

  return 0;
}