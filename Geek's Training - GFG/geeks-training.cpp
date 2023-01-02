//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int helper(vector<vector<int>> &points, int n, int prev, vector<vector<int>> &dp) {
        if(n == 0) {
            int res = INT_MIN;
            for(int i = 0; i < 3; i++) {
                if(i != prev) {
                    res = max(res, points[n][i]);
                }
            }
            return res;
        }
        if(dp[n][prev] != -1) {
            return dp[n][prev];
        }
        int res = INT_MIN;
        for(int i = 0; i <= 2; i++) {
            if(prev == 3 || i != prev) {
                res = max(res, helper(points, n - 1, i, dp) + points[n][i]);
            }
        }
        return dp[n][prev] = res;
    }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(points.size(), vector<int>(4, -1));
        return helper(points, n - 1,  3, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends