#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> &visited, unordered_map<int, vector<int>> &mp){
        visited[node] = 1 - visited[node];

        for(int nei: mp[node]){
            if(visited[nei] == 0) dfs(nei, visited, mp);
        }

    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < invocations.size(); i++){
            mp[invocations[i][0]].push_back(invocations[i][1]);
        }

        vector<int> visited(n, 0);
        dfs(k, visited, mp);

        vector<int> ans;

        for(int i = 0; i < invocations.size(); i++){
            int u = invocations[i][0];
            int v = invocations[i][1];

            if(!visited[u] && visited[v]){
                for(int i = 0; i < n; i++){
                    ans.push_back(i);
                }
                return ans;
            }

        }

        for(int node = 0; node < n; node++){
            if(visited[node] == 0) ans.push_back(node);
        }

        return ans;
    }   
};