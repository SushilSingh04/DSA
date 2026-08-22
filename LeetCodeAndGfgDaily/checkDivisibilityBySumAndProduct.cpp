#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitProd = 1;
        int tmp = n;

        while(n > 0){
            digitSum += n % 10;
            digitProd *= n % 10;
            n /= 10;
        }

        return tmp % (digitSum + digitProd) == 0 ? true : false;
    }
};