import time

# from twinkle import Twinkle
from thermo import Thermo
################################################################################
# Main
################################################################################
# twinkle = Twinkle()
t = Thermo()
while True:
    t.run()
    time.sleep(5.0)