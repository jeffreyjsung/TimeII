import serial
import argparse

#Setup serial interface
ser = serial.Serial()
ser.baudrate = 115200

parser = argparse.ArgumentParser()
parser.add_argument("Tests", help="'run' --Runs all tests\n",
                    type='String')
args = parser.parse_args()

if ('run' in args):
    #TODO ADD TESTS