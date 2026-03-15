// This file acts as the main driver/library

/*
  SDA: GPIO 3
  SDI: MOSI: 19
  SDO: MISO: 21
  SCLK: 23

  SPI_CE0: 24   TFT Chip Select
  SPI_CE1: 26   Touch Controller Chip Select

    ILI:
  GPIO 25:
  GPIO 24:
  GPIO 23: Switch 1: 16
  GPIO 22: Switch 2: 15
  GPIO 21: Switch 3: 13
  GPIO 18: Switch 4: 12
  GPIO 4:
*/

#include <iostream> // IO operations
#include <chrono>   // Time Utilities
#include <thread>   // For Pausing/Sleeping Purposes

#include <gpiod.h>

int read_switch(struct gpiod_chip *chip, const char *line_name, unsigned int offset)
{
  struct gpiod_line *line = gpiod_chip_get_line(chip, offset);

  int value = gpiod_line_get_value(line);
  gpiod_line_release(line);
  return value;
}

int main(int argc, char *argv[])
{
  struct gpiod_chip *chip = gpiod_chip_open_by_name("gpiochip0");
  if (!chip)
  {
    std::cout << "Failed to open GPIO chip!" << std::endl;
    return 1;
  }

  while (true)
  {
    int sw1 = read_switch(chip, "Switch 1", 16);
    int sw1 = read_switch(chip, "Switch 1", 15);
    int sw1 = read_switch(chip, "Switch 1", 13);
    int sw1 = read_switch(chip, "Switch 1", 12);
  }
  /*
  std::cout << "Hello, World!" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "Slept for 500 ms!" << std::endl;
*/
  return 0;
}