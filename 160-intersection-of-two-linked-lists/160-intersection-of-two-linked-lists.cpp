/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1 = 0, c2 = 0;
        ListNode* first = headA, *second = headB;
        while(first != NULL) {
            first = first->next;
            c1++;
        } 
        while(second != NULL) {
            second = second->next;
            c2++;
        } 
        int times = abs(c1 - c2); 
        first = headA;
        second = headB;
        if(c1 > c2) {
            while(times--) {
                first = first->next;
            }
        } else {
            while(times--) {
                second = second->next;
            }
        }   
        while(first != NULL && second != NULL) {
            if(first == second) {
                return first;
            }
            first = first->next;
            second = second->next;
        }
        return NULL;
    }
};