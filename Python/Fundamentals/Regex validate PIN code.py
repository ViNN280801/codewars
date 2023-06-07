def validate_pin(pin: str) -> bool:
    """ Returns True if 'pin' is 4-digit or 6-digit PIN-code """
    if (len(pin) == 4 or len(pin) == 6) and pin.isdigit():
        return True
    return False
