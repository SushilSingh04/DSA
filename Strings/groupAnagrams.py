'''
1. Loop over strs, sort each string
2. Put it into dictionary as a key 
Eg: 'ate','eat','tea' all belong to key 'aet'
3. End dictionary: {'aet':['ate','eat','tea'] ...}
4. Append all values in the dictionary to a new list
'''


def groupAnagrams(self, strs):
    d = {}
    for i in range(len(strs)):
        curr = strs[i]
        curr = ''.join(sorted(curr))
        d.setdefault(curr,[]).append(strs[i])

    l = []
    for key in d:
        l.append(d[key])
    return l