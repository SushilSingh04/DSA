#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26, 0);
        int n = target.length();
        int oddCnt = 0;
        char oddCh;

        for(char c: s) freq[c-'a']++;

        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 == 1){
                oddCnt++;
                oddCh = i + 'a';
            }
        }

        if(oddCnt > 1) return "";

        int i = 0;
        string halfAns = "";

        
        while(i < n/2){
            char ch = target[i];

            if(freq[ch-'a'] >= 2){
                halfAns += target[i];
                freq[ch-'a'] -= 2;
            }
            else break;
            i++;
        }
        // cout << halfAns << " ";

        if(i == n/2){
            string ans = halfAns;
            if(n % 2 == 1){
                ans += oddCh;
            }
            for(int k = halfAns.length()-1; k >= 0; k--){
                ans += halfAns[k];
            }
            if(ans > target){
                return ans;
            }
        }

        if(i < n/2){
            char ch = target[i];
            int j = ch-'a'+1;

            while(j < 26){
                if(freq[j] >= 2){
                    halfAns += j+'a';
                    freq[j] -= 2;

                    for(int k = 0; k < 26; k++){
                        while(freq[k] >= 2){
                            halfAns += char('a'+k);
                            freq[k] -= 2;
                        }
                    }
                    
                    string ans = halfAns;
                    if(n % 2 == 1) ans += oddCh;

                    for(int k = halfAns.size()-1; k >= 0; k--){
                        ans += halfAns[k];
                    }
                    return ans; 
                }
                j++;
            }    
        }

        // cout << halfAns << " ";
        while(!halfAns.empty()){
            char ch = halfAns.back();
            halfAns.pop_back();
            freq[ch-'a'] += 2;

            for(char j = ch+1; j <= 'z'; j++){
                if(freq[j-'a'] >= 2){
                    halfAns += j;
                    freq[j-'a'] -= 2;

                    for(int k = 0; k < 26; k++){
                        while(freq[k] >= 2){
                            halfAns += 'a' + k;
                            freq[k] -= 2;
                        }
                    }
                    
                    string ans = halfAns;
                    if(oddCnt == 1){
                        ans += oddCh;
                    }

                    for(int k = halfAns.length()-1; k >= 0; k--){
                        ans += halfAns[k];
                    }
                    return ans; 
                }
            }
        }

        return "";
    }
};