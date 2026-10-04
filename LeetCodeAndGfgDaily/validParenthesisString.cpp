#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int maxOpen = 0, minOpen = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                maxOpen++;
                minOpen++;
            }
            else if(s[i] == ')'){
                maxOpen--;
                minOpen--;
            }
            else if(s[i] == '*'){
                maxOpen++;
                minOpen--;
            }

            if(maxOpen < 0) return false;
            // clip it to 0 that means take * as ""
            if(minOpen < 0) minOpen = 0;
        }
        return minOpen == 0;
    }
};