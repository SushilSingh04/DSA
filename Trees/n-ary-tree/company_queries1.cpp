#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int main(){
    int n,q;
    cin >> n;
    cin >> q;
    vector<vector<int>> binaryLifting(n+1, vector<int> (31-1));
    for(int i=2; i<=n; i++){
        int a;
        cin >> a;
        // a is the boss of i
        binaryLifting[i][0] = a;
    }

    for (int j=1; j <= 30; j++){
        for(int i=1; i<=n; i++){
            int firstParent = binaryLifting[i][j-1];
            if(firstParent != -1){
                binaryLifting[i][j] = binaryLifting[firstParent][j-1];
            }
        }
    }
    
    while (q--){
        int x, k;
        cin >> x;
        cin >> k;
        for(int j=30; j>=0; j--){
            if(k & (1 << j)){
                x = binaryLifting[x][j];
            }
            if (x == -1){
                break;
            }
            cout << x << endl;
        }
    }
}
