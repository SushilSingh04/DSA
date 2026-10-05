#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s, int i){
        stack<int> st;
        st.push(0);

        for(char ch: s){
            if(ch == '('){
                st.push(0);
            }
            else{
                int v = st.top(); st.pop(); // score of inner level so far
                int w = st.top(); st.pop(); // score of outer level
                st.push(w + max(2*v, 1));
            }
        }
        return st.top();
    }

    int scoreOfParentheses(string s) {
        
        return solve(s, 0);
    }
};