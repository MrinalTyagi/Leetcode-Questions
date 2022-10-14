/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0 || head->next == NULL) {
            return head;
        }
        int count = 0;
        ListNode *temp = head;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        k = k % count;
        if(k == 0) {
            return head;
        }
        
        temp = head;
        while(temp != NULL && k) {
            k--;
            temp = temp->next;
        }
        
        ListNode *curr = head;
        while(temp != NULL && temp->next != NULL) {
            curr = curr->next;
            temp = temp->next;
        }
        
        ListNode *newHead = curr->next;
        temp->next = head;
        curr->next = NULL;
        return newHead;
    }
};