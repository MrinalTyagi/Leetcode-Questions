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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }
        int carry = 0;
        ListNode *temp1 = l1, *temp2 = l2;
        ListNode *head = NULL, *tail = NULL;
        while(temp1 != NULL && temp2 != NULL) {
            int val = temp1->val + temp2->val + carry;
            carry = val / 10;
            ListNode *newNode = new ListNode(val % 10);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        while(temp1 != NULL) {
            int val = temp1->val + carry;
            carry = val / 10;
            ListNode *newNode = new ListNode(val % 10);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            temp1 = temp1->next;
        }
        
        while(temp2 != NULL) {
            int val = temp2->val + carry;
            carry = val / 10;
            ListNode *newNode = new ListNode(val % 10);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            temp2 = temp2->next;
        }
        
        while(carry != 0) {
            int val = carry;
            carry = carry / 10;
            ListNode *newNode = new ListNode(val % 10);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        return head;
    }
};