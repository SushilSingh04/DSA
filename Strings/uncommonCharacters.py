# Based on symmetric difference between two sets

def uncommonChars(self, s1, s2):
    #code here
    set1 = set(s1) # direct set conversion without involving list
    set2 = set(s2)
    res_set = set1 ^ set2 # symmetric difference
    return ''.join(sorted(res_set))

