#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for(int i = 0; i < reservedSeats.size(); i++){
            int row = reservedSeats[i][0], seat = reservedSeats[i][1];
            mp[row] += (1 << (10-seat));
        }
        
        int groups = 0;

        for(auto it: mp){
            int num = it.second;
            int i = 8;
            cout << "row " << it.first << endl;
            while(i >= 5){
                if((num & (1 << i)) == 0){
                    i--;
                }
                else break;
            }
            cout << i << endl;

            if(i >= 6){
                i = 6;
                while(i >= 3){
                    if((num & (1 << i)) == 0){
                        i--;
                    }
                    else break;
                }
            }
            else if(i == 4) groups++;
            cout << i << endl;

            if(i >= 4){
                i = 4;
                while(i >= 1){              
                    if((num & (1 << i)) == 0){
                        i--;
                    }
                    else break;
                }
            }
            else if(i == 2) groups++;

            if(i == 0) groups++;
        }

        groups += (n - mp.size())*2;
        return groups;
    }
};