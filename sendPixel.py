#!/usr/bin/python3

import serial
ser = serial.Serial('/dev/ttyUSB0',9600)

variable = "7,5,0,255,0"
ser.write(variable.encode())
