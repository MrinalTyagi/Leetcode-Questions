class DisjointSet {
    public:
    int v;
    int *parent, *rank;
    
    DisjointSet(int v) {
        this->v = v;
        this->parent = new int[v];
        this->rank = new int[v];
        for(int i = 0; i < v; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findParent(int u) {
        if(parent[u] == u) {
            return u;
        }
        parent[u] = findParent(parent[u]);
        return parent[u];
    }
    
    void unionRank(int u, int v) {
        int p1 = findParent(u);
        int p2 = findParent(v);
        if(p1 != p2) {
            if(rank[p1] < rank[p2]) {
                parent[p1] = p2;
            } else if(rank[p1] > rank[p2]) {
                parent[p2] = p1;
            } else {
                parent[p2] = p1;
                rank[p1]++;
            }
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra = 0;
        for(auto x: connections) {
            int u = x[0], v = x[1];
            if(ds.findParent(u) != ds.findParent(v)) {
                ds.unionRank(u, v);
            } else {
                extra++;
            }
        }
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            s.insert(ds.findParent(i));
        }
        if(extra >= s.size() - 1) {
            return s.size() - 1;
        } else {
            return -1;
        }
    }
};