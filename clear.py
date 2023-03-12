#!/usr/bin/python3

import serial
ser = serial.Serial('/dev/ttyUSB0',9600)
ser.write(b'clear')

