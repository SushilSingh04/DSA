#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        int cntOne = s[0] == '0' ? 0 : 1;

        if(s[0] == '0') a[0] = 1;
        if(s[n-1] == '0') b[n-1] = 1;
        // 01010

        for(int i = 1; i < s.length(); i++){
            if(s[i] == '0'){
                a[i] = a[i-1] + 1;
            }
            else{
                cntOne++;
                a[i] = 0;
            }
        }

        for(int i = n-2; i >= 0; i--){
            if(s[i] == '0'){
                b[i] = b[i+1] + 1;
            }
            else{
                b[i] = 0;
            }
        }

        int maxDelta = 0;
        int i = 1;

        while(i < n-1){
            if(s[i] == '1' && a[i-1] > 0){
                int delta = a[i-1];
                while(i < n-1 && s[i] == '1' && s[i] == s[i+1]) i++;
                if(i < n-1 && s[i] == '1') delta += b[i+1];
                else delta = 0;

                maxDelta = max(maxDelta, delta);
            }
            i++;
        }
        
        return maxDelta + cntOne;   
    }
};