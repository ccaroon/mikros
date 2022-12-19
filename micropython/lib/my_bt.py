# https://github.com/micropython/micropython-lib/tree/master/micropython/bluetooth/aioble
import aioble
import uasyncio

"""
>>> import uasyncio
>>> from my_bt import MyBT
>>> uasyncio.run(MyBT.find_devices())
"""

class MyBT:

    @classmethod
    def find_devices(cls, timeout=5000):
        uasyncio.run(cls.__find_devices(timeout))

    @classmethod
    async def __find_devices(cls, timeout=5000):
        async with aioble.scan(5000) as scanner:
            async for result in scanner:
                # if result.name():
                print(result, result.name(), result.rssi, result.services())
