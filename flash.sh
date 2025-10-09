#!/bin/sh
set -e
cmake --build build
mount /dev/sdb1 /mnt/rpi
cp ./build/lift.uf2 /mnt/rpi
umount /dev/sdb1
