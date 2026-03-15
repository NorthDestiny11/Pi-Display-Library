#!/bin/bash

# Fail if any commands or parts fail or if any variables are undefined
set -euo pipefail
#
# This file is designed to configure the Raspberry Pi
#

# Make sure script is run as root:
if [[ $EUID -ne 0 ]]; then
  echo "Please run this script as root. Preface the command with sudo." 1>&2
  exit 1
fi

sudo apt update
sudo apt upgrade

# Install GCC if not installed already
sudo apt install build-essential

# Download and enable pigpio
sudo apt install pigpio
sudo systemctl start pigpiod
sudo systemctl enable pigpiod

# Enable SPI
sudo raspi-config nonint do_spi 0

echo "All required interfaces have been enabled. Would you like to reboot now?"

# Rebooting script for changes to take effect
read -p "Would you like to reboot now? (y/N): " answer
answer=$(echo "$answer" | tr '[:upper:]' '[:lower:]')

if [[ "$answer" == "y" ]]; then
    echo "Rebooting..."
    echo "Don't forget to drink water today."
    sleep 3
    sudo reboot
else
    echo "Reboot skipped. Changes will take effect on next boot."
fi

