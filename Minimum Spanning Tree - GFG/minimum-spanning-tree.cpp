//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> dist(V, INT_MAX);
        vector<bool> mset(V, false);
        dist[0] = 0;
        int weight = 0;
        for(int j = 0; j < V; j++) {
            int index = -1;
            for(int i = 0; i < dist.size(); i++) {
                if(!mset[i] && (index == -1 || dist[i] < dist[index])) {
                    index = i;
                }
            }
            mset[index] = true;
            weight+=dist[index];
            for(auto x: adj[index]) {
                int val = x[0];
                int wt = x[1];
                if(!mset[val] && (dist[val] > wt)) {
                    dist[val] = wt;
                }
            }
        }
        return weight;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends