#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        // 1,000,000,000,000,000
        //     1,000,000,000,000
        //         1,000,000,000
        //             1,000,000
        //               100,000
        // 1000*0 + (1,000,000 - 1,000)*1
        long long tmp = n;
            
        int cntDigits = 0;
        while(tmp != 0){
            cntDigits++;
            tmp /= 10;
        }
        // 5,000,000
        // (1,000,000-1,000)*1 + 5,000,000-1,000,000
        int grp = 3, lvl = 1;
        long long cntCommas = 0;
        while(grp + 3 <= cntDigits){
            cntCommas += lvl * (min(n, (long long)pow(10,grp+3)) - pow(10,grp)) + 1;
            grp += 3;
            lvl++;
        }

        if(grp < cntDigits){
            cout << n << " " << (long long)pow(10,grp);
            cntCommas += lvl*(n - (long long)pow(10,grp)) + 1;
        }

        return cntCommas;
    }
};