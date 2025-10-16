#!/bin/sh
set -e
cmake --build build
sudo mount /dev/sda1 /mnt/rpi
sudo cp ./build/lift.uf2 /mnt/rpi
sudo umount /dev/sda1
