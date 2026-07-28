#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> arr(26,0);

        for(char c: s){
            arr[c - 'a']++;
        }

        int i = 0, j = n-1;
        for(int k = 0; k < 26; k++){
            while(i < j && arr[k] > 1){
                s[i++] = (char)('a' + k);
                s[j--] = (char)('a' + k);
                arr[k] -= 2;
            }
        }

        return s;

    }
};