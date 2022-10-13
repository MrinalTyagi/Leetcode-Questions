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
        if(headA == NULL && headB == NULL) {
            return NULL;
        }
        ListNode *temp1 = headA, *temp2 = headB;
        int a = 0, b = 0;
        while(temp1 != NULL) {
            a++;
            temp1 = temp1->next;
        }
        while(temp2 != NULL) {
            b++;
            temp2 = temp2->next;
        }
        int moves = abs(a - b);
        temp1 = headA, temp2 = headB;
        if(a - b > 0) {
            while(moves) {
                moves--;
                temp1 = temp1->next;
            }
        } else {
            while(moves) {
                moves--;
                temp2 = temp2->next;
            }
        }
        
        while(temp1 != NULL && temp2 != NULL) {
            if(temp1 == temp2) {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};