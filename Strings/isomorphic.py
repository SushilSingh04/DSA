def isIsomorphic(s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        arr1 = [0]*256
        arr2 = [0]*256

        for i in range(len(s)):
            # Last seen position of both characters should be same
            if arr1[ord(s[i])] != arr2[ord(t[i])]:
                return False
            # Update the last seen position (can't be 0 becuase both lists are initialized with zero)
            arr1[ord(s[i])] = i+1
            arr2[ord(t[i])] = i+1

        return True

isIsomorphic("egg", "add")