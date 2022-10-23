//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
struct my_comparator
{
    // queue elements are vectors so we need to compare those
    bool operator()(vector<int> &a, vector<int> b)
    {
        return a[0] > b[0];
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> res;
        int count = 0;
        priority_queue<vector<int>, vector<vector<int>>, my_comparator> pq;
        for(auto x: arr) {
            pq.push(x);
            count += x.size();
        }
        while(count) {
            count--;
            vector<int> top = pq.top();
            pq.pop();
            res.push_back(top[0]);
            top.erase(top.begin());
            if(top.size() != 0) {
                pq.push(top);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends