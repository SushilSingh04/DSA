def countGoodNumbers(n: int) -> int:
        MOD = 10**9+7
        def power(x, n):
            result = 1
            while n > 0:
                if n % 2 == 1:
                    result = (result * base) % MOD
                base = (base*base) % MOD
                n //= 2
            return result
        even_pos = (n+1)//2
        odd_pos = n//2
        return (pow(5,even_pos)*pow(4,odd_pos)) % MOD

# print(countGoodNumbers(641263))
print(countGoodNumbers(806166225460393))