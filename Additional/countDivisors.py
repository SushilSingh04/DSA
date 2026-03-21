def countDivisors(n):
        cnt = 0
        i = 1
        while i*i <= n:
            if n%i == 0:
                cnt += 1
            if i*i != n and n%i == 0:
                cnt += 1
            i += 1
        return cnt

def countDivisorsDivisibleBy3(n):
        cnt = 0
        i = 1
        while i*i <= n:
            if n%i == 0 and i % 3 == 0:
                cnt += 1
            if i*i != n and n%i == 0 and (n//i) % 3 == 0:
                cnt += 1
            i += 1
        return cnt

print(countDivisors(36)) # Output: 9
print(countDivisorsDivisibleBy3(10)) # Output: 0
print(countDivisors(25)) # Output: 3
print(countDivisorsDivisibleBy3(25)) # Output: 0
print(countDivisors(1)) # Output: 1
print(countDivisorsDivisibleBy3(1)) # Output: 0