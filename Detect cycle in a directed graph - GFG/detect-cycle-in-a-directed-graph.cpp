//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool helper(int index, vector<int> *adj, vector<bool> &visited, vector<bool> &dfsvis) {
        visited[index] = true;
        dfsvis[index] = true;
        for(auto x: adj[index]) {
            if(!visited[x]) {
                if(dfsvis[x] || helper(x, adj, visited, dfsvis)) {
                    return true;
                }
            } else {
                if(dfsvis[x]) {
                    return true;
                } 
            }
        }
        dfsvis[index] = false;
        return false;
    }
 
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> dfsvis(V, false);
        for(int i = 0; i < V; i++) {
            if(!visited[i] && helper(i, adj, visited, dfsvis)) {
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends