#!/usr/bin/env python
import os.path as path
from pprint import pformat
import yaml
# .secrets file should be formatted thusly
# ---------------------------------------
# secrets:
#     thing1: foo
#     thing2: bar
# ---------------------------------------
root_path = path.dirname(path.abspath(__file__)) + '/..'
dot_secrets =  root_path + "/.secrets"
with open(dot_secrets, "r") as file:
    data = yaml.safe_load(file)

secrets = data.get('secrets', {})
with open("%s/lib/secrets.py" % (root_path), "w") as file:
    file.write("SECRETS = ")
    file.write(pformat(secrets))
