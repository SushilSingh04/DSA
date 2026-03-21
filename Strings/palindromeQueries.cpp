#include<bits/stdc++.h>
using namespace std;

int main(){
    int q; cin >> q;
    string s; cin >> s;
    int n = s.size();
    int pref[n] = {0};
    for(int i=0; i<n; i++){
        int bits = s[i] - 'a';
        pref[i] = ((i-1 >= 0 ? pref[i-1] : 0) ^ (1ll << bits));
    }
    for(int i=0; i < q; i++){
        int l, r; cin >> l >> r;
        r -= 1;
        l -=1;
        int currXr = pref[r];
        if(l-1 >= 0) currXr ^= pref[l-1];
        int len = r-l+1;
        if(len % 2 == 0){
            cout << (currXr == 0 ? 'Possible' : 'Impossible') << endl;
        }
        else{
            cout << ((currXr & (currXr - 1)) == 0 ? 'Possible' : 'Impossible');
        }
    }
}