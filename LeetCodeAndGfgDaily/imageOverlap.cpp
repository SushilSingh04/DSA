#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxOverlapping = 0;
        int n = img1.size();
        vector<vector<int>> count(2*n-1, vector<int>(2*n-1,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 0) continue;
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        if(img1[i][j] == img2[k][l]){
                            if(img2[k][l] == 0) continue;
                            int xTrans = k-i, yTrans = l-j;
                            xTrans = xTrans + n-1;
                            yTrans = yTrans + n-1;
                            
                            maxOverlapping = max(maxOverlapping, ++count[xTrans][yTrans]);
                        }
                    }
                }
            }
        }

        return maxOverlapping;
    }
};