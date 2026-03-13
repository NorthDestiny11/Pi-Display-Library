import gpiozero
from time import sleep

# Do not assign any power pins. This is handled by the display.
# Only SCK, MOSI, MISO, CE0, CE1, GPIO 25, GPIO 24 are to be touched.

#Both 3.3V Power supplies are used.

V3_3_1 = 1
V3_3_2 = 17

# Both 5V Power supplied are used.

V5_1 = 2
V5_2 = 4

# Module recieves GND Via GPIO 25. All other Ground Pins are unused.

GND_1 = 6 
GND_2 = 9
GND_3 = 14
GND_4 = 20
GND_5 = 25

MOSI = 10
MISO = 9
SCLK = 11

CE0 = 8
CE1 = 7

IO24 = 18
IO25 = 22

# I believe, according to the schematic, that the touchscreen may be using GPIO 2/3.

# Resolution is 230x240 px.
# 16-bit color pixels

#
# READ INTO: https://learn.adafruit.com/adafruit-pitft-28-inch-resistive-touchscreen-display-raspberry-pi/downloads
#
