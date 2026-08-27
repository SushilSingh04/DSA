#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for(char c: s){
            freq[c-'a']++;
        }
        vector<int> tmp = freq;
        
        string ans = "";
        int i = 0;

        bool strictlyGreater = false;

        while(i < target.length()){
            if(freq[target[i]-'a'] > 0){
                ans += target[i];
                freq[target[i]-'a']--;
                i++;
            }
            else break;
        }
        
        
        if(i < s.length()){
            char ch = target[i];
            int j = ch-'a'+1;
            while(j < 26){
                if(freq[j] > 0){
                    ans += j+'a';
                    freq[j]--;
                    strictlyGreater = true;
                    break;
                }
                j++;
            }    
        }
        // cout << strictlyGreater << " " << ans << endl;
        while(!ans.empty() && !strictlyGreater){
            char ch = ans.back();
            ans.pop_back();
            // cout << ans << " " << ch << " ";
            for(char k = ch+1; k <= 'z'; k++){
                // cout << k << " ";
                if(freq[k-'a'] > 0){
                    ans += k;
                    // cout << ans << " " << k << " " << freq[k-'a'] << " ";
                    strictlyGreater = true;
                    freq[k-'a']--;
                    break;
                }
            }
            freq[ch-'a']++;
        }
        
        if(ans == "") return "";
        for(int k = 0; k < 26; k++){
            while(freq[k] > 0){
                ans += k+'a';
                freq[k]--;
            }
        }

        return ans != target ? ans: "";

    }
};