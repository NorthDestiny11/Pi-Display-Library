// This file acts as the main driver/library

/*
  SDA: 3
  SDI: MOSI: 19
  SDO: MISO: 21
  SCLK: 23

  SPI_CE0: 24   TFT Chip Select
  SPI_CE1: 26   Touch Controller Chip Select

    ILI:
  GPIO 25: DC: 22
  GPIO 24:
  GPIO 23: Switch 1: 16
  GPIO 22: Switch 2: 15
  GPIO 21: Switch 3: 13
  GPIO 18: Switch 4: 12
  GPIO 4: Real Time Interupt: 7
*/

#include "includes.h"
#include "definitions.h"

void spi_write(uint8_t *data, size_t len)
{
  struct spi_ioc_transfer tr = {};
  tr.tx_buf = (unsigned long)data;
  tr.len = len;
  tr.speed_hz = speed;
  tr.bits_per_word = bits;

  ioctl(spi_fd, SPI_IOC_MESSAGE(1), &tr);
}

void send_command(uint8_t cmd)
{
  gpiod_line_set_value(dc_line, 0);
  spi_write(&cmd, 1);
}

void send_data(uint8_t *data, size_t len)
{
  gpiod_line_set_value(dc_line, 1);
  spi_write(data, len);
}

void reset()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(120));
}

void init()
{
  send_command(0x01); // Software reset
  std::this_thread::sleep_for(std::chrono::milliseconds(5));

  // Figure out what I'm even doing haha (HELP!)
}

int main(int argc, char *argv[])
{
  return 0;
}