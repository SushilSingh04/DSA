#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        int num = n;

        while(true){
            int tmp = num;
            int prod = 1;
            while(tmp){
                prod *= tmp % 10;
                tmp /= 10;
            }
            if(prod % t == 0) return num;
            num++;
        }          
    }
};