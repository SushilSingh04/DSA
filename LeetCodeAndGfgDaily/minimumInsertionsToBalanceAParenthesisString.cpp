#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int i = 0, ans = 0;

        while(i < s.length()){
            char ch = s[i];
            if(ch == '(') st.push(ch);
            else if(ch == ')'){
                if(i+1 < s.length() && s[i+1] == ')'){ // found two closed brackets
                    if(!st.empty()) st.pop(); // already have a single open for two closed no need to increment ans
                    else ans++; // one single bracket needed
                    i++;
                }
                else if(!st.empty()){ // one single open and closed bracket present just need one more
                    ans++;
                    st.pop();
                }
                else{ // single closed bracket, need one open and one closed bracket
                    ans += 2;
                }
            }
            i++;
        }

        ans += 2*st.size(); // for each remanining open brackets need two more closed

        return ans;
    }
};