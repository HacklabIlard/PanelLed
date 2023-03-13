#!/usr/bin/python3

import numpy as np
from PIL import Image
import serial
import time
import sys

ser = serial.Serial('/dev/ttyUSB0',9600)

def sendImage(image_name):
    img = Image.open(image_name)

    img_array = np.array(img)

    my_array = img_array.reshape((10, 10, 3))

    color_flat = my_array.flatten()

    color_str = ''.join(map(chr, color_flat))


    string_converted = color_str.encode()

    ser.write(string_converted)

sendImage(sys.argv[1] + '.png')
