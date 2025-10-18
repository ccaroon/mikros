from SETTINGS import DATA as settings

class Config:
    @classmethod
    def get(cls, name, default=None):
        value = settings

        parts = name.split(":")
        for part_name in parts:
            value = value.get(part_name, default)
            if value == default:
                break

        return value
