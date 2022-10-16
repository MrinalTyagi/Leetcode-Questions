//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    stack<int> Reverse(stack<int> St){
        if(St.size() == 1) {
            return St;
        }
        int temp = St.top();
        St.pop();
        stack<int> smallRes = Reverse(St);
        stack<int> s2;
        while(!smallRes.empty()) {
            s2.push(smallRes.top());
            smallRes.pop();
        }
        smallRes.push(temp);
        while(!s2.empty()) {
            smallRes.push(s2.top());
            s2.pop();
        }
        return smallRes;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        stack<int> ans=ob.Reverse(St);
        vector<int>res;
        while(ans.size())
        {
            res.push_back(ans.top());
            ans.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends