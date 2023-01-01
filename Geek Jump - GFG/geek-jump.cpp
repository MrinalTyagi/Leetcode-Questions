//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(vector<int> &height, int n, vector<int> &dp) {
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int first = helper(height, n - 1, dp) + abs(height[n] - height[n - 1]);
        int second = INT_MAX;
        if(n - 2 >= 0) {
            second = helper(height, n - 2, dp) + abs(height[n] - height[n - 2]);
        }
        int res = min(first, second);
        return dp[n] = res;
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n, -1);
        return helper(height, n - 1, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends