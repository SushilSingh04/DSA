#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<int> tmp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                tmp.push_back(grid[i][j]);
            }
        }
        k %= m*n;

        reverse(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.begin() + k);
        reverse(tmp.begin() + k, tmp.end());

        int l = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] = tmp[l++];
            }
        }

        return grid;
    }
};