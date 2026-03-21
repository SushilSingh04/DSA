from typing import List
    
# 1. Using Bit Manipulation
def readBinaryWatch(self, turnedOn: int) -> List[str]:
        output = []
        for h in range(12):
            for m in range(60):
                if bin(h).count('1') + bin(m).count('1') == turnedOn:
                    time = f"{h}:{m:02d}"
                    output.append(time)
        return output


# 2. Backtracking
def readBinaryWatch(turnedOn: int) -> List[str]:
    leds = [1,2,4,8,1,2,4,8,16,32]
    output = []
    backtrack(0, turnedOn, 0,0,leds, output)
    return output

def backtrack(idx, remOn, curr_h, curr_m, leds, output):
    if remOn == 0:
        time = f"{curr_h}:{curr_m:02d}"
        output.append(time)
        return

    if idx == 10:
        return 
    if idx < 4:
        # Turn on idx led only if hour doesn't exceed 11(Pruning)
        if curr_h + leds[idx] < 12:
            backtrack(idx+1, remOn-1,curr_h+leds[idx],curr_m,leds, output)
    else:
        # Turn on idx led only if minute doesn't exceed 59(Pruning)
        if curr_m + leds[idx] < 60:
            backtrack(idx+1, remOn-1, curr_h, curr_m+leds[idx],leds, output)
    # Move idx but don't turn on idx led
    backtrack(idx+1, remOn, curr_h, curr_m, leds, output)