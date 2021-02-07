import importlib

def get_instance(obj, **kwargs):
    """Create new instance of the ``obj`` argument.

    Args:
        obj (str, type, instance):
    """
    instance = None
    if isinstance(obj, str):
        package, name = obj.rsplit('.', 1)
        instance = getattr(importlib.import_module(package), name)(**kwargs)

    elif isinstance(obj, type):
        instance = obj(**kwargs)

    else:
        if kwargs != dict():
            instance = obj.__class__(**kwargs)

        else:
            instance = obj.__class__(*obj.__args__, **obj.__kwargs__)

    return instance
