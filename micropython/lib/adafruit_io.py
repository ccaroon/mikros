import urequests

class AdafruitIO:
    BASE_URL = "https://io.adafruit.com/api/v2"

    def __init__(self, group, secrets):
        self.__username = secrets['aio_username']
        self.__key      = secrets['aio_key']

        self.__group_name = group

    # TODO: use kwargs for non-required feed data fields
    def publish_data(self, feed, value, dry_run = False):
        feed_name = "%s.%s" % (self.__group_name, feed)
        data = {"value": value}

        url = "%s/%s/feeds/%s/data" % (AdafruitIO.BASE_URL, self.__username, feed_name)
        headers = {'X-AIO-Key': self.__key}

        output = None
        if dry_run:
            output = {
                "success": True,
                "dry_run": True,
                "results": {
                    "url": url,
                    "headers": headers,
                    "data": data
                }
            }
        else:
            resp = urequests.post(url, headers=headers,json=data)

            if resp.status_code == 200:
                output = {
                    "success": True,
                    "results" : resp.json()
                }
            else:
                output = {
                    "success": False,
                    "code": resp.status_code,
                    "feed": feed_name,
                    "value": value,
                    "msg": resp.json()['error']
                }

        return (output)
