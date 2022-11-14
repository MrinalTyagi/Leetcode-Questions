class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> arr[n + 1];
        for(auto x: times) {
            arr[x[0]].push_back({x[1], x[2]});
        }
        priority_queue<pair<int, int>> pq;
        vector<int> dist(n + 1, INT_MAX);
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto x: arr[node]) {
                int index = x.first;
                int weight = x.second;
                if(d + weight < dist[index]) {
                    dist[index] = d + weight;
                    pq.push({dist[index], index});
                }
            }
        }
        int ans = -1;
        for(int i = 1; i<=n; i++) {
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};