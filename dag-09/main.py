import json
from hashlib import md5

def decode(arr, previous_hash):
    found = None
    for idx, item in enumerate(arr):
        ch = item[0]
        hash = item[1]
        test_hash = md5("{}{}".format(previous_hash, ch)).hexdigest()
        if test_hash == hash:
            found = item
            found_idx = idx
            break
    del arr[found_idx]
    if len(arr) == 0:
        return found[0]
    else:
        return found[0] + decode(arr, found[1])

input_as_json = json.loads(open("input-hashchain.json").read().strip())
input_as_tuples = map(lambda x: (str(x['ch']), str(x['hash'])), input_as_json)

first_hash = md5("julekalender").hexdigest()
answer = decode(input_as_tuples, first_hash)

print(answer)
