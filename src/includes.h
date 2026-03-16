#pragma once

#include <iostream> // IO operations
#include <chrono>   // Time Utilities
#include <thread>   // For Pausing/Sleeping Purposes

#include <linux/spi/spidev.h>
#include <gpiod.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>