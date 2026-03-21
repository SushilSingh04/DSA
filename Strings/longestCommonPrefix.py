from typing import List

def longestCommonPrefix(strs: List[str]) -> str:
        # Sorting seems to be the best option
        sorted_strs = sorted(strs)
        if sorted_strs[0] == "":
            return ""
        i = 0
        # biggest difference will be between the first and the last
        min_ = min(len(sorted_strs[0]), len(sorted_strs[-1]))
        # Now compare between them till what point are they same
        while(i < min_ and sorted_strs[0][i] == sorted_strs[-1][i]):
            i += 1
        return sorted_strs[0][:i]

lst = ['flower', 'flow', 'flight']
longestCommonPrefix()