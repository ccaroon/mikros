
# LogFile
# Indicator
# AdafruitIO

class Notifier:

    __instance = None

    def __init__(self, *args):
        if not Notifier.__instance:
            Notifier.__instance =  Notifier.__Instance(args)

    def __getattr__(self, name):
        return getattr(Notifier.__instance, name)

    # -------------------------------------------------------------------------
    class __Instance:
        def __init(self):
            self.__recipients = args

        def debug(self, msg):
            self.__notify("debug", msg)

        def info(self, msg):
            self.__notify("info", msg)

        def warn(self, msg):
            self.__notify("warn", msg)

        def error(self, msg):
            self.__notify("error", msg)

        def critical(self, msg):
            self.__notify("critical", msg)

        def __notify(self, level, msg):
            for r in self.__recipients:
                r.notify(level, msg)
