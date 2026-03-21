import sys
data = sys.stdin.read().strip().split('\n')
n = int(data[0])
probImplemented = 0
for line in data[1:]:
    cnt = 0
    for i in range(0,len(line),2):
        if line[i] == '1':
            cnt += 1

    if cnt >= 2:
        probImplemented += 1

print(probImplemented)