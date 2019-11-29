# import upip
# import uos

from chronos import Chronos

print("----- START BOOT -----")
# if "lib" not in uos.listdir():
#     uos.mkdir("lib")

# if "logging.py" not in uos.listdir('./lib'):
#     upip.install("logging")

print("    --> Chronos.sync() begin...")
Chronos.sync()
print("    --> Chronos.sync() end.")

print("------ END BOOT ------")
