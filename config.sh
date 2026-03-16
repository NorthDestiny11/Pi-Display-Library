#!/bin/bash

#
# This file is designed to configure the Raspberry Pi
# Library designed by NorthDestiny11
#

# Fail if any commands or parts fail or if any variables are undefined
set -euo pipefail

# Make sure script is run as root:
if [[ $EUID -ne 0 ]]; then
  echo "Please run this script as root. Preface the command with sudo." 1>&2
  exit 1
fi

sudo apt update
sudo apt upgrade

# Install GCC if not installed already
sudo apt install build-essential

# Download libgpiod for proper processing from the GPIO header
sudo apt install gpiod libgpiod-dev

# Enable SPI
sudo raspi-config nonint do_spi 0

cd ~

# Compile the C++ file
echo "Compiling C++ Driver..."


# Copy the auto-run .service file to a safe, permanent space to run on boot. 

#
#
#   DO NOT RUN THE FOLLOWING LINES OF CODE UNTIL A STABLE RELEASE HAS BEEN PUBLISHED
#
#

: '

#sudo cp -f Northian-Display-Library.service /etc/systemd/system

# Compile file to /usr/local/bin to be stored safely and permanently
#sudo g++ -o /usr/local/bin/Northian-Display-Driver "$HOME"/Pi-TFT-Driver/main.cpp -lgpiod -lpthread --pedantic

'


echo "All required interfaces have been enabled. Would you like to reboot now?"

# Rebooting script for changes to take effect
read -p "Would you like to reboot now? (y/N): " answer
answer=$(echo "$answer" | tr '[:upper:]' '[:lower:]')

if [[ "$answer" == "y" || "$answer" == "yes" ]]; then
    echo "Rebooting..."
    echo "Don't forget to drink water today."
    sleep 3
    sudo reboot
else
    echo "Reboot skipped. Changes will take effect on next boot."
fi