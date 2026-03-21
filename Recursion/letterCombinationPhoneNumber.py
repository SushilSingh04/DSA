from typing import List

# 1. Create a map
# 2. Maintain a pointer idx
# 3. for each idx traverse over all characters of the keyboard for that digits (ex. for '2' -> 'abc')
# 4. append each character in currString : List[str]
# 5. Recurse generate for next idx
# 6. Pop out last character from currString
# 7. Base Case - idx == len(digits), append currString in ans in the form of string
def letterCombinations(digits: str) -> List[str]:
        ans = []
        keyboard = {'2':'abc', '3':'def', '4':'ghi','5':'jkl', '6':'mno','7':'pqrs', '8':'tuv', '9':'wxyz'}
        def generate(idx: int, currString):
            if idx == len(digits):
                ans.append(''.join(currString.copy()))
                return
            for ch in keyboard[digits[idx]]:
                currString.append(ch)
                generate(idx+1, currString)
                currString.pop()
        generate(0,[])
        return ans