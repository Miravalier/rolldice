#!/bin/bash
rm -f /dev/dice
mknod /dev/dice c $(awk '/dice/{print $1}' /proc/devices) 1
