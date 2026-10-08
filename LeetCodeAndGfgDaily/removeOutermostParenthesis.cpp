#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string ans = "";

        for(int j = 0; j < s.length(); j++){
            if(s[j] == '('){
                if(open > 0) ans += '(';
                open++;
            }
            else{
                open--;
                if(open > 0) ans += ')';
            }
        }

        return ans;
    }
};