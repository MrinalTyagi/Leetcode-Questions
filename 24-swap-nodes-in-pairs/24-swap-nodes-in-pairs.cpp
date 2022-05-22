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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *prev = NULL, *curr = head, *next = NULL, *finalHead = NULL;
        
        while(curr != NULL && curr->next != NULL) {
            next = curr->next;
            curr->next = next->next;
            next->next = curr;
            if(prev != NULL) {
                prev->next = next;
            } else {
                finalHead = next;
            }
            prev = curr;
            curr = prev->next;
        }
        return finalHead;
    }
};