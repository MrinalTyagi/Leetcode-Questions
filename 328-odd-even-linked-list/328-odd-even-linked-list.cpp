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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *temp = head, *evenHead = NULL, *evenTail = NULL, *oddHead = NULL, *oddTail = NULL;
        int count = 1;
        while(temp != NULL) {
            if(count % 2 == 0) {
                if(evenHead == NULL) {
                    evenHead = temp;
                    evenTail = temp;
                } else {
                    evenTail->next = temp;
                    evenTail = temp;
                }
            } else {
                if(oddHead == NULL) {
                    oddHead = temp;
                    oddTail = temp;
                } else {
                    oddTail->next = temp;
                    oddTail = temp;
                }
            }
            count++;
            temp = temp->next;
        }
        
        
        if(oddHead == NULL) {
            return evenHead;
        } else if(evenHead == NULL) {
            evenTail->next = NULL;
            return evenTail;
        } else {
            oddTail->next = evenHead;
            evenTail->next = NULL;
            return oddHead;
        }
        
        
    }
};