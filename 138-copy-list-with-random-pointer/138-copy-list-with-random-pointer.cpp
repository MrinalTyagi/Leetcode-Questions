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
        Node *temp = head;
        while(temp != NULL) {
            Node *t = new Node(temp->val);
            t->next = temp->next;
            temp->next = t;
            temp = temp->next->next;
        }
        
        temp = head;
        while(temp != NULL) {
            temp->next->random = (temp->random != NULL) ? temp->random->next : NULL;
            temp = temp->next->next;
        }
        
        Node *original = head, *copy = head->next;
        temp = copy;
        while(original && temp) {
            original->next = (original->next != NULL) ? original->next->next : NULL;
            original = original->next;
            temp->next = (temp->next != NULL) ? temp->next->next : NULL;
            temp = temp->next;
        }
        return copy;
        
        
    }
};