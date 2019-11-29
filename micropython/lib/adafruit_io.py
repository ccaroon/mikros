import secrets
import urequests

class AdafruitIO:
    BASE_URL = "https://io.adafruit.com/api/v2"

    def __init__(self, group):
        self.__username = secrets.secrets['aio_username']
        self.__key      = secrets.secrets['aio_key']

        self.__group_name = group

    def get_data(self, feed, **kwargs):
        feed_name = "%s.%s" % (self.__group_name, feed)

        limit = kwargs.get('limit', 1)
        fields = ['value']
        fields.extend(kwargs.get('fields', []))
        include = ','.join(fields)
        url = F"{AdafruitIO.BASE_URL}/{self.__username}/feeds/{feed_name}/data?limit={limit}&include={include}"
        headers = {'X-AIO-Key': self.__key}

        resp = requests.get(url, headers=headers)

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
                "msg": resp.json()['error']
            }

        return (output)


    # TODO: use kwargs for non-required feed data fields
    def publish_data(self, feed, value, **kwargs):
        dry_run = kwargs.get('dry_run', False)
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
            resp = urequests.post(url, headers=headers, json=data)

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

    def handle_response(self, resp):
        if resp['success'] and resp.get('dry_run', False):
            results = resp['results']
            print("DRY RUN: [%s] -> %s" % (results['data']['value'], results['url']))
        elif resp['success']:
            results = resp['results']
            print("%s - %s: [%s]" % (results['id'], results['feed_key'], results['value']))
        else:
            error_msg = "AIO: [%s] -> [%s] | %d - %s " % (resp['value'], resp['feed'], resp['code'], resp['msg'])
            raise Exception(error_msg)








#
