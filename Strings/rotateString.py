from typing import List

def rotateString(s: str, goal: str) -> bool:
        if len(s) != len(goal): 
            return False
        elif len(s) == 0:
            return True
        res = s+s
        # must appear in res
        if goal in res:
            return True
        else:
            return False
        
rotateString("abcde", "cdeab")