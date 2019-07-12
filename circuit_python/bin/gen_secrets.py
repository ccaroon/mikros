#!/usr/bin/env python
import yaml

# .secrets file should be formatted thusly
# ---------------------------------------
# secrets:
#     ssid: SSID
#     password: PASSWD
#     timezone: "America/New_York"
#     aio_username: NONE
#     aio_key: None
# ---------------------------------------
with open('.secrets', "r") as file:
    data = yaml.load(file)

secrets = data.get('secrets', {})
with open("secrets.py", "w") as file:
    file.write(F"""
secrets = {{
    'ssid':         '{secrets.get("ssid", "NONE")}',
    'password':     '{secrets.get("password", "NONE")}',
    'timezone':     "{secrets.get("timezone","NONE")}",
    'aio_username': "{secrets.get("aio_username","NONE")}",
    'aio_key':      "{secrets.get("aio_key","NONE")}",
}}
""")
