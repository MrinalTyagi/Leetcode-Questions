//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void helper(int index, vector<int> *adj, vector<int> &res, vector<bool> &visited) {
        queue<int> q;
        q.push(index);
        visited[index] = true;
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            for(auto x: adj[temp]) {
                if(!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<int> res;
        // for(int i = 0; i < V; i++) {
        //     if(!visited[i]) {
        //         helper(i, adj, res, visited);
        //     }
        // }
        helper(0, adj, res, visited);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends