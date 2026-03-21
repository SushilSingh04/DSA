# Number is going to repeat
# 2 -> 4 -> 16 -> 37-> 58 -> 89 -> 145 -> 42 -> 20 -> 4 (repeated)
# maintain a hashmap

def isHappy(n: int) -> bool:
    # 0 1 4 9 16 25 36 49 64 81 
    # 1 + 9 = 10
    seen_before = {}
    num = n
    while num not in seen_before:
        seen_before[num] = seen_before.get(num,0)+1
        sum_sq = 0
        while num > 0:
            rem = num % 10
            sum_sq += rem*rem
            # print(sum_sq, rem)
            num //= 10
        num = sum_sq
        # print(num, end=" ")
        if num == 1:
            return True
    return False
