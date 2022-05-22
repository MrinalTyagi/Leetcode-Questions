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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || (n == 1 && head->next == NULL)) {
            return NULL;
        }
        ListNode *first = head;
        ListNode *second = head;
        ListNode *temp = NULL;
        while(n--) {
            first = first->next;
        }
        while(first != NULL) {
            first = first->next;
            temp = second;
            second = second->next;
        }
        
        if(temp != NULL) {
            temp->next = second->next;
        } else {
            head = head->next;
        }
        return head;

    }
};