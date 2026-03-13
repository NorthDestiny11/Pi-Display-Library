#!/bin/bash

#
# This file is designed to configure the Raspberry Pi
#

# Make sure script is run as root:
if [[ $EUID -ne 0 ]]; then
  echo "Please run this script as root. Preface the command with sudo." 1>&2
  exit 1
fi

# Enable SPI, I2C, UART respectively
sudo raspi-config nonint do_spi 0
sudo raspi-config nonint do_i2c 0

echo "All required interfaces have been enabled. Would you like to reboot now?"

# Rebooting script for changes to take effect
read -p "Would you like to reboot now? (Y/N): " answer
answer=$(echo "$answer" | tr '[:upper:]' '[:lower:]')

if [[ "$answer" == "y" || "$answer" == "yes" ]]; then
    echo "Rebooting..."
    sudo reboot
else
    echo "Reboot skipped. Changes will take effect on next boot."
fi
