from typing import List

class ProductOfNumbers:

    def __init__(self):
        self.prefixProd = [1]
        self.nums = []

    def add(self, num: int) -> None:
        if num == 0:
            self.prefixProd = [1]
        else:
            self.nums.append(num)
            self.prefixProd.append(self.prefixProd[-1]*num)
        # print(self.prefixProd)

    def getProduct(self, k: int) -> int:
        # print(self.prefixProd, k)
        n = len(self.prefixProd)
        if k >= len(self.prefixProd):
            return 0
        return self.prefixProd[-1]//self.prefixProd[n-k-1]
