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
        if(head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode *t = head;
        while(n) {
            t = t->next;
            n--;
        }
        if(t == NULL) {
            return head->next;
        }
        ListNode *slow = head;
        while(t != NULL && t->next != NULL) {
            t = t->next;
            slow = slow->next;
        }
        ListNode *del = slow->next;
        if(del != NULL) {
            slow->next = del->next;
        } else {
            slow->next = NULL;
        }
        delete del;
        return head;
    }
};