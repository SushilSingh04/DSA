#include <iostream>
using namespace std;

bool stringMatch(string text, string pattern){
    int n = text.size();
    int m = pattern.size();
    int j=0;
    // while(j<m){
        for(int i=0; i<n-m; i++){
            if(text[i] == pattern[j]){
                j++;
            }
            if(j == m) return true;
        }
        return false;
    // }
}

int main(){
    // string s = "abcdecdf";
    // string j = "dec";
    // // cout << (s.substr(3,3) == j);
    // cout << stringMatch(s,j);
    int fact= 1, num = 5;
    while(num>1){
        fact *= num;
        num--;
    }
    cout << fact;
}