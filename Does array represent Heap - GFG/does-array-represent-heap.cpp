//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int parent(int i) {
        return ((i - 1) / 2);
    }
    
    int left(int i) {
        return 2 * i + 1;
    }
    
    int right(int i) {
        return 2 * i + 2;
    }
    
    bool check(int a[], int n, int i) {
        if(i >= n) {
            return true;
        }

        if(left(i) <= n && a[i] <= a[left(i)]) {
            return false;
        }
        if(right(i) <= n && a[i] <= a[right(i)]) {
            return false;
        }
        return (check(a, n, left(i)) && check(a, n, right(i)));
    }
    
    bool isMaxHeap(int a[], int n)
    {
        // Your code goes here
        for(int j = n - 1; j >= 0; j--) {
            if(!check(a, n, j)) {
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends