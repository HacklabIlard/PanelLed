#!/usr/bin/python3

import numpy as np
from PIL import Image
import serial
ser = serial.Serial('/dev/ttyUSB0',9600)

# Load the image
img = Image.open('image.png')

# Convert the image to a numpy array
img_array = np.array(img)

# Reshape the array to a 3-dimensional array with shape (10, 10, 3)
print("my_array")
my_array = img_array.reshape((10, 10, 3))

print(my_array)


# flatten the array
print("color_fla")
color_flat = my_array.flatten()

print(color_flat)

# convert the flattened array to a string
print("color_str")
color_str = ''.join(map(chr, color_flat))

print(color_str)

string_converted = color_str.encode()

# send the string to Arduino
print("string_converted")
print(string_converted)

#

ser.write(string_converted)

