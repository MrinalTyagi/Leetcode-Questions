//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr, arr + n);
    pair<int, int> res;
    if(n == 0) {
        return res;
    }
    int start = 0, end = n - 1;
    int mid;
    int res1 = -1;
    while(start <= end) {
        mid = (start + end) / 2;
        if(arr[mid] == x) {
            res1 = arr[mid];
            break;
        } else if(arr[mid] < x) {
            res1 = arr[mid];
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    } 
    int res2 = -1;
    start = 0, end = n - 1;
    while(start <= end) {
        mid = (start + end) / 2;
        if(arr[mid] == x) {
            res2 = arr[mid];
            break;
        } else if(arr[mid] < x) {
            start = mid + 1;
        } else {
            res2 = arr[mid];
            end = mid - 1;
        }
    } 
    res.first = res1;
    res.second = res2;
    return res;
}