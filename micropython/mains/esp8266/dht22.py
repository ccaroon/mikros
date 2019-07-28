from machine import Pin

import dht


d = dht.DHT22(Pin(4))
d.measure()
print(d.temperature()) # eg. 23.6 (°C)
print(d.humidity())    # eg. 41.3 (% RH)
