import re


def solution(s: str) -> str:
    """ Returns broken string by camel case with whitespace separator """
    result = str()
    for ch in s:
        if (ch.isupper()):
            result += " " + ch
        else:
            result += ch
    return result


def solution_clever(s):
    return ''.join(' ' + c if c.isupper() else c for c in s)


def solution_regex(s):
    return re.sub('([A-Z])', r' \1', s)


print(solution("breakCamel"))
print(solution("identifier"))
print(solution(""))
print(solution("breakCamelCase"))
print(solution("ehagdacHdcdfebbdCddHfcabhcFafegAbhdebGgh"))

print(solution_clever("breakCamel"))
print(solution_clever("identifier"))
print(solution_clever(""))
print(solution_clever("breakCamelCase"))
print(solution_clever("ehagdacHdcdfebbdCddHfcabhcFafegAbhdebGgh"))

print(solution_regex("breakCamel"))
print(solution_regex("identifier"))
print(solution_regex(""))
print(solution_regex("breakCamelCase"))
print(solution_regex("ehagdacHdcdfebbdCddHfcabhcFafegAbhdebGgh"))
