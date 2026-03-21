# We count valley not when taking a step down but when taking a step up and reaching altitude 0

def countingValleys(steps, path):
    altitude = 0
    valleys = 0
    
    for step in path:
        if step == 'U':
            altitude += 1
            # If we just reached 0 by stepping up, we completed a valley
            if altitude == 0:
                valleys += 1
        else:
            altitude -= 1
            
    return valleys

# Alternate Approach
def countingValleys2(steps, path):
    level = 0
    downSteps = 0
    upSteps = 0
    valleys = 0
    for step in path:
        if step == 'U' and downSteps == upSteps:
            level += 1
        elif step == 'D' and downSteps == upSteps:
            valleys += 1
            level -= 1
        if step == 'U':
            upSteps += 1
        else:
            downSteps += 1
    return valleys