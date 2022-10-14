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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head, *newHead = NULL, *newTail = NULL;
        while(temp != NULL) {
            ListNode *prev = NULL, *curr = temp, *next = NULL;
            int count = 0;
            ListNode *cnt = temp;
            int c = k;
            while(cnt != NULL && c) {
                c--;
                count++;
                cnt = cnt->next;
            }
            if(count < k) {
                newTail->next = temp;
                break;
            } else {
                for(int i = 0; i < k && curr != NULL ; i++){
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                if(newHead == NULL) {
                    newHead = prev;
                    newTail = temp;
                } else {
                    newTail->next = prev;
                    newTail = temp;
                }
                temp = curr;   
            }
        }
        return newHead;
    }
};