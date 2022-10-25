//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	int starting(int nums[], int target, int n) {
        int start = 0, end = n - 1;
        int mid;
        while(start <= end) {
            mid = (start + end) / 2;
            if(nums[mid] == target) {
                if(mid == 0 || nums[mid - 1] != nums[mid]) {
                    return mid;
                } else {
                    end = mid - 1;   
                }
            } else if(nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
    
    int ending(int nums[], int target, int n) {
        int start = 0, end = n - 1;
        int mid;
        while(start <= end) {
            mid = (start + end) / 2;
            if(nums[mid] == target) {
                if(mid == n - 1 || nums[mid + 1] != nums[mid]) {
                    return mid;
                } else {
                    start = mid + 1;
                }
            } else if(nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }	
		
		
	int count(int arr[], int n, int x) {
	    // code here
	    int first = starting(arr, x, n);
	    if(first == -1) {
	        return 0;
	    }
	    return ending(arr, x, n) - first + 1;
	}
};

//{ Driver Code Starts.

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
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends