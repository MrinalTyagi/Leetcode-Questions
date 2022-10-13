//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node *reverse(Node *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        Node *res = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return res;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        if(head == NULL) {
            return head;
        }
        Node *temp = reverse(head);
        Node *temp2 = temp;
        int carry = 0;
        Node *prev = NULL;
        bool isFirst = true;
        while(temp2 != NULL) {
            prev = temp2;
            int val = temp2->data + carry;
            if(isFirst) {
                val++;
            }
            isFirst = false;
            carry = val / 10;
            temp2->data = val % 10;
            temp2 = temp2->next;
        }
        Node *finalhead = NULL, *tail = NULL;
        while(carry != 0) {
            int val = carry;
            carry = carry / 10;
            Node *newNode = new Node(val % 10);
            if(finalhead == NULL) {
                finalhead = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        if(finalhead != NULL) {
            prev->next = finalhead;
        }
        return reverse(temp);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends