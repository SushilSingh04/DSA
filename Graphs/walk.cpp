#include<bits/stdc++.h>
using namespace std;

#define int long long int
int n;

vector<vector<int>> matrixMul(vector<vector<int>> &A, vector<vector<int>> &B){
    vector<vector<int>> ans (n, vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                ans[i][j] += A[i][k] + B[k][j];
            }
        }
    }
}

vector<vector<int>> matExp(vector<vector<int>> &A, int k){
    vector<vector<int>> res(n, vector<int>(n,0));
    while(k > 0){
        if(k & 1){
            res = matrixMul(res, A);
        }
        else{
            A = matrixMul(A,A);
        }
        k = k >> 1;
    }

}

int main(){
    vector<vector<int>> A(n, vector<int>(n,0));
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }
}