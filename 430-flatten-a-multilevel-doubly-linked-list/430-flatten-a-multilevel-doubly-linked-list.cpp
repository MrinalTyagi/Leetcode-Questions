/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL || (head->next == NULL && head->child == NULL)) {
            return head;
        }
        
        
        Node *nextNode = flatten(head->next);
        Node *childNode = flatten(head->child);
        if(childNode != NULL) {
            Node *temp = childNode;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = head->next;
            if(nextNode != NULL) {
             nextNode->prev = temp;   
            }
            head->next = childNode;
            childNode->prev = head;
        }
        head->child = NULL;
        return head;   
    }
};