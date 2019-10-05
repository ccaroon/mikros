import os

def delete_all_files(path="."):
    for file in os.listdir(path):
        full_name = "%s/%s" % (path, file)
        try:
            os.remove(full_name)
            print("(F) %s ... OK" % (full_name))
        except OSError as e:
            if "EISDIR" in str(e):
                delete_all_files(full_name)
                os.rmdir(full_name)
                print("(D) %s ... OK" % (full_name))
            else:
                print("%s ... %s" % (full_name, e))
