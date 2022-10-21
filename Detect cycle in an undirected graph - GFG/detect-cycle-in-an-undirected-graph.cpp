//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int index, vector<int> *adj, vector<bool> &visited) {
        queue<pair<int, int>> q;
        q.push({index, -1});
        visited[index] = true;
        while(!q.empty()) {
            int temp = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto x: adj[temp]) {
                if(!visited[x]) {
                    visited[x] = true;
                    q.push({x, temp});
                } else {
                    if(parent == -1 || x == parent) {
                        continue;
                    }
                    return true;
                }
            }
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++) {
            if(!visited[i] && bfs(i, adj, visited)) {
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends