import logging

class LogFile:

    __inited = False

    @classmethod
    def init(cls, name):
        if not cls.__inited:
            log_stream = open("%s.log" % name, "a")
            logging.basicConfig(stream=log_stream, level=logging.INFO)
            cls.__inited = True

    @classmethod
    def get_logger(cls, name):
        return logging.getLogger(name)
