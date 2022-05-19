#!/usr/bin/env python

import RPi.GPIO as GPIO
from mfrc522 import SimpleMFRC522

reader = SimpleMFRC522()

try:
        id, text = reader.read()
        print("Python: " + id)
        f = open("text.txt", "w")
        f.write(str(id))
        f.close()
finally:
        GPIO.cleanup()
