#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i =0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<int> dist(n+1, 1e18);
    dist[1] = 0;
    multiset<pair<int, int>> ms;
    ms.insert({0,1});
    while(ms.size()){
        int node = (*ms.begin()).second;
        if((*ms.begin()).first > dist[node]){
            ms.erase(ms.begin());
            continue;
        }
        ms.erase(ms.begin());
        for(auto [ch, cost]: adj[node]){
            if(dist[node] + cost < dist[ch]){
                dist[ch] = dist[node] + cost;
                ms.insert({dist[ch], ch});
            }
        }
    }

}