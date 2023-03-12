#!/usr/bin/python3

import serial
ser = serial.Serial('/dev/ttyUSB0',9600)
variable = "letter"
ser.write(variable.encode())

