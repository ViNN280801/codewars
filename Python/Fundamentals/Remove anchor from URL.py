def remove_url_anchor(url: str) -> str:
    """ Removes all characters behind the anchor '#' and anchor itself """
    return url.split('#')[0]