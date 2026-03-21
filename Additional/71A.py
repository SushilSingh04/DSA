import sys
data = sys.stdin.read().strip().split()

n = int(data[0])
for word in data[1:]:
    # 4
    # n = 0
    if n < 1:
        break
    if len(word) <= 10:
        print(word)
    elif len(word) > 10:
        print(word[0] + str(len(word) - 2) + word[-1])
    n -= 1
