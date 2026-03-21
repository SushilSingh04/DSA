n = int(input())
label = ''
while n > 0:
    rem = n % 26
    n //= 26
    # print(n,rem)
    if rem == 0:
        label += 'Z'
        n -=1
    else:
        label += chr(64+rem)
print(label[::-1])