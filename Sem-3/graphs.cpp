// BFS
#include<bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>> adj, int n, int u){
    vector<int> result;
    vector<int> visited(n,0);
    queue<int> q;
    //Push starting element
    q.push(u);
    visited[u] = 1;
    // Till the queue is empty
    while(!q.empty()){
        int v=q.front();
        q.pop();
        // Store it in result
        result.push_back(v);
        // Traverse through all its neighbour
        for(auto nei: adj[v]){
            //If not visited push in the queue
            if(visited[nei] == 0 ){
                q.push(nei); 
                visited[nei] = 1;
            }

        }
    }
    return result;

}

void dfs(vector<vector<int>> adj, vector<int> &visited, vector<int> &result, int u){
    visited[u] = 1;
    result.push_back(u);
    for(auto nei : adj[u]){
        if(!visited[nei]){
            dfs(adj, visited, result, nei);
        }
    }
}

vector<int> dfsOfGraph(vector<vector<int>> adj, int n){
    vector<int> visited(n,0);
    vector<int> result;
    dfs(adj, visited, result, 1);

    return result;
}

void addEdge(vector<vector<int>> &adj, int v, int u){
    adj[v].push_back(u);
    adj[u].push_back(v);
}

int main(){
    vector<vector<int>> adj(9);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,5);
    addEdge(adj,2,6);
    addEdge(adj,3,4);
    addEdge(adj,3,7);
    addEdge(adj,7,8);
    addEdge(adj,4,8);

    // for(auto nei: adj){
    //     for(int i:nei){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    for(int val: dfsOfGraph(adj, 9)){
        cout << val << " ";
    }

    // for(int val: bfs(adj, 5, 0)){
    //     cout << val << " ";
    // }




}

// void add_edge(int adj[100][100], int src, int dest) {
//     adj[src][dest] = 1;
//     adj[dest][src] = 1;  // since it's an undirected graph
// }

// bool BFS(int adj[100][100], int source, int destination, int v, int pred[], int dist[]) {
//     // Arrays to track visited nodes and distances
//     bool visited[100] = {false};  
//     int queue[100];  // Simulate the queue using an array
//     int front = 0, rear = 0;
    
//     visited[source] = true;
//     dist[source] = 0;
//     queue[rear++] = source;
// while (front < rear) {
//         int u = queue[front++];
        
//         // Visit all the neighbors of u
//         for (int i = 0; i < v; i++) {
//             if (adj[u][i] == 1 && !visited[i]) {  // If there is an edge and i is unvisited
//                 queue[rear++] = i;
//                 visited[i] = true;
//                 dist[i] = dist[u] + 1;
//                 pred[i] = u;

//                 // If we have reached the destination, no need to explore further
//                 if (i == destination) {
//                     return true;
//                 }
// }
//         }
//     }

//     return false;  // If there is no path from source to destination
// }

// void printShortestDistance(int adj[100][100], int source, int destination, int v, int pred[], int dist[]) {
//     if (dist[destination] == INT_MAX) {
//         cout << "No path exists between " << source << " and " << destination << endl;
//         return;
//     }
// cout << "Shortest path length is: " << dist[destination] << endl;

//     // Reconstruct the path from destination to source using the pred array
//     int path[100];
//     int pathLength = 0;
//     int temp = destination;

//     while (temp != source) {
//         path[pathLength++] = temp;
//         temp = pred[temp];
//     }
//     path[pathLength] = source;

//     cout << "Path is: ";
//     for (int i = pathLength; i >= 0; i--) {
//         cout << path[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int v, e;
//     cin >> v >> e;

//     int adj[100][100] = {0};  // Initialize adjacency matrix
//     for (int i = 0; i < e; i++) {
//         int src, dest;
//         cin >> src >> dest;
//         add_edge(adj, src, dest);
//     }

//     int source, destination;
//     cin >> source >> destination;

//     int pred[100], dist[100];
//     for (int i = 0; i < v; i++) {
//         pred[i] = -1;  // No predecessor initially
//         dist[i] = INT_MAX;  // Infinite distance initially
//     }

//     if (BFS(adj, source, destination, v, pred, dist)) {
//          printShortestDistance(adj, source, destination, v, pred, dist);
//     } else {
//         cout << "No path found." << endl;
//     }

//     return 0;
// }
