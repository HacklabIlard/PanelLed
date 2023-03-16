#!/usr/bin/python3

import numpy as np
from PIL import Image
import serial
import time
import sys

ser = serial.Serial('/dev/ttyUSB0',9600)


def color2alpha(arr):
    new_arr = []
    for old_value in arr:
        new_value = int((old_value / 255) * 25 + 97)
        new_arr.append(new_value)
    return new_arr

def sendImage(image_name):
    img = Image.open(image_name)

    img_array = np.array(img)

    #print(img_array)

    my_array = img_array.reshape((10, 10, 3))

    color_flat = my_array.flatten()
    
    print(color_flat)

    new_color_flat = color2alpha(color_flat)

    print(new_color_flat)

    color_str = ''.join(map(chr, new_color_flat))

    print(color_str)

    string_converted = color_str.encode()

    print(string_converted)

    ser.write(string_converted)

sendImage(sys.argv[1] + '.png')
