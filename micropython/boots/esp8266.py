import upip
import uos

from chronos import Chronos

if "logging.py" not in uos.listdir('/lib'):
    upip.install("logging")

Chronos.sync()
