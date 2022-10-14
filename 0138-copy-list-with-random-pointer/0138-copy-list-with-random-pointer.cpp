/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return NULL;
        }
        unordered_map<Node *, Node *> m;
        Node *temp = head;
        while(temp != NULL) {
            m[temp] = new Node(temp->val);
            temp = temp->next;
        }
        for(auto x: m) {
            if(x.first != NULL) {
                x.second->next = m[x.first->next];
                x.second->random = m[x.first->random];
            }
        }
        return m[head];
    }
};