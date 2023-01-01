//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n, -1);
        dp[0] = 0;
        for(int i = 1; i < n; i++) {
            int first = dp[i - 1] + abs(height[i] - height[i - 1]);
            int second = INT_MAX;
            if(i - 2 >= 0) {
                second = dp[i - 2] + abs(height[i] - height[i - 2]);
            }
            int res = min(first, second);
            dp[i] = res;
        }
        return dp[n - 1];
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