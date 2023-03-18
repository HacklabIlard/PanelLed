Panel Led
=========


#### 1/ Programme Arduino.

```
panel_led.ino
```


#### 2/ Programme Python3.

- Initialisation de l'interface série :  

```
$ python3
Python 3.10.6 (main, Nov 14 2022, 16:10:14) [GCC 11.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import serial;
>>> ser = serial.Serial('/dev/ttyUSB0',9600)
```

- Envoyer l'image :  

```
./convertSendImage2Arduino.py image_color.png
```
