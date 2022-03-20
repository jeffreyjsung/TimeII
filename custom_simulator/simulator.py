import tkinter as tk
from PIL import Image, ImageTk
import serial
import os
import time
import random
import sys
import glob

# Colors
darkish = '#%02x%02x%02x' % (29, 30, 38)
whitish = '#%02x%02x%02x' % (214, 216, 218)
code_green = '#%02x%02x%02x' % (80, 200, 70)
code_green_light = '#%02x%02x%02x' % (170, 200, 150)
code_dark = '#%02x%02x%02x' % (23, 24, 30)

root = tk.Tk()