import upip
import uos

from chronos import Chronos

if "lib" not in uos.listdir():
    uos.mkdir("lib")

if "logging.py" not in uos.listdir('./lib'):
    upip.install("logging")

Chronos.sync()
