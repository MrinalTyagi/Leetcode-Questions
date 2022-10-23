//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indeg(V, 0);
        for(int i = 0; i < V; i++) {
            for(auto x: adj[i]) {
                indeg[x]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < indeg.size(); i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            count++;
            for(auto x: adj[temp]) {
                indeg[x]--;
                if(indeg[x] == 0) {
                    q.push(x);
                }
            }
        }
        if(count == V) {
            return false;
        }
        return true;
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