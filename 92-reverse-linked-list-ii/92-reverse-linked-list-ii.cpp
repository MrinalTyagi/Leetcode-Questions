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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || right <= left) {
            return head;
        }
        ListNode *prev = NULL, *curr = NULL, *next = NULL;
        ListNode *temp = NULL;
        int count = 1;
        while(count < left) {
            if(temp == NULL) {
                temp = head;
            } else {
                temp = temp->next;   
            }
            count++;
        }
        
        
        prev = (temp == NULL) ? NULL : temp->next;
        curr = (temp == NULL) ? head : prev->next;
        if(temp != NULL) {
            count++;
        }
        while(count <= right) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(temp == NULL) {
            head->next = curr;
            return prev;
        } else {
            temp->next->next = curr;
            temp->next = prev;
            return head;
        }

    }
};