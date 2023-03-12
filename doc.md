util01@station173:~$ python3
Python 3.10.6 (main, Nov 14 2022, 16:10:14) [GCC 11.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import serial;
>>> ser = serial.Serial('/dev/ttyUSB0',9600)
>>> variable = "send"
>>> ser.write(variable.encode())
4
>>>

util01@station173:~/Arduino/panel_led_8$ python3 ./sendletter.py 
util01@station173:~/Arduino/panel_led_8$ python3 ./clearletter.py 
