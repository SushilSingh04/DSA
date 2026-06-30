#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3] = {0,0,0};
        int cntSubStrings = 0;
        int l = 0;
        for(int r = 0; r < s.length(); r++){
            arr[s[r] - 'a']++;
            while(arr[0] > 0 && arr[1] > 0 && arr[2] > 0){
                // if current substring contains all three char then all the substrings to the right will also be valid
                cntSubStrings += s.length() - r;
                arr[s[l] - 'a'] -= 1;
                l++;
            }
        }

        return cntSubStrings;



    }
};