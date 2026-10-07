#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    bool isValid(string s){
        if(!ans.empty() && ans.back() == s) return false;
        int open = 0, closed = 0;
        for(char ch: s){
            if(ch == ')') closed++;
            else if(ch == '(') open++;

            if(closed > open) return false;
        }
        return open == closed;
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        bool found = false;

        while(!q.empty()){
            int qsize = q.size();

            while(qsize--){
                string tmp = q.front(); q.pop();

                if(isValid(tmp)){
                    found = true;
                    ans.push_back(tmp);
                    continue;
                }

                if(found) continue; // so that last line would return ans

                for(int i = 0; i < tmp.length(); i++){
                    string newS = tmp.substr(0, i) + tmp.substr(i+1, tmp.length()-(i+1));
                    if(tmp[i] != ')' && tmp[i] != '('){
                        continue;
                    }
                    if(!visited.count(newS)){
                        visited.insert(newS);
                        q.push(newS);
                    }
                }

            }

            if(found) return ans;
        }

        return ans;
    }
};