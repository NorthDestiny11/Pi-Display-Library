#pragma once
#include "includes.h"

#define SPI_DEV "/dev/spidev0.0"

#define DC_PIN 22

#define TFT_WIDTH 240
#define TFT_HEIGHT 320

int spi_fd;

uint8_t mode = SPI_MODE_0;
uint8_t bits = 8;
uint32_t speed = 32000000;

gpiod_chip *chip;
gpiod_line *dc_line;

#define CHIP_NAME "gpiochip0"

#define SWITCH_1 16
#define SWITCH_2 15
#define SWITCH_3 13
#define SWITCH_4 12