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

    print(color_flat)

    ser.write(color_flat)


sendImage(sys.argv[1])
