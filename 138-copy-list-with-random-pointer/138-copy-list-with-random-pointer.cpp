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
        unordered_map<Node *, Node*> h;
        Node *temp = head;
        while(temp != NULL) {
            Node *t = new Node(temp->val);
            h[temp] = t;
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL) {
            Node *t = h[temp];
            t->next = h[temp->next];
            t->random = h[temp->random];
            temp = temp->next;
        }
        return h[head];
        
    }
};