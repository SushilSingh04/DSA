# Approach 1- sort both the strings and check if they are equal

# Approach 2- create two dictionaries and then if any character frequency doesn't match return false

# Approach 3(Optimal Approach)- Initialize a 26 length array and 
# Traverse first string: increment frequency of each character 
# Traverse second string: decrement frequency of each character 
# if freq array is all zero then the strings are anagrams

def isAnagram(s: str, t: str) -> bool:
    if len(s) != len(t):
        return False
    arr = [0]*26
    for ch in s:
        arr[ord(ch)-97] += 1
    for ch in t:
        arr[ord(ch)-97] -= 1
    
    if arr == [0]*26:
        return True
    return False
    
isAnagram("egg", "geg")

