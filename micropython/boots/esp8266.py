import upip
import uos

from chronos import Chronos

print("--- Boot ...")
if "lib" not in uos.listdir():
    uos.mkdir("lib")

if "logging.py" not in uos.listdir('./lib'):
    upip.install("logging")

Chronos.sync()
print("--- End Boot ---")
