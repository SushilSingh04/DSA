#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int cnt = 0;
        int i = 0, j = k-1;
        while(j < s.length()){
            if(j-i+1 >= k+1){
                if(isPalindrome(s,i,j)){
                    cnt++;
                    i=j+1;
                    j = i+k-1;
                }
                else{
                    i++;
                    j= i+k-1;
                }
            }
            else if(isPalindrome(s,i,j)){
                cnt++;
                i = j+1;
                j = i+k-1;
            }
            else j++;
        }

        return cnt;
    }
};