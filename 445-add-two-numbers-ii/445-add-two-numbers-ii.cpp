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
    
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode *finalHead = NULL, *finalTail = NULL;
        ListNode *first = l1, *second = l2;
        int carry = 0;
        
        while(first != NULL && second != NULL) {
            int data = first->val + second->val + carry;
            carry = (data / 10);
            int val = data % 10;
            ListNode *newNode = new ListNode(val);
            if(finalHead == NULL) {
                finalHead = newNode;
                finalTail = newNode;
            } else {
                finalTail->next = newNode;
                finalTail = newNode;
            }
            first = first->next;
            second = second->next;
        }
        
        while(first != NULL) {
            int data = first->val + carry;
            carry = (data / 10);
            int val = data % 10;
            ListNode *newNode = new ListNode(val);
            if(finalHead == NULL) {
                finalHead = newNode;
                finalTail = newNode;
            } else {
                finalTail->next = newNode;
                finalTail = newNode;
            }
            first = first->next;
        }
        
        while(second != NULL) {
            int data = second->val + carry;
            carry = (data / 10);
            int val = data % 10;
            ListNode *newNode = new ListNode(val);
            if(finalHead == NULL) {
                finalHead = newNode;
                finalTail = newNode;
            } else {
                finalTail->next = newNode;
                finalTail = newNode;
            }
            second = second->next;
        }
        
        if(carry != 0) {
            ListNode *newNode = new ListNode(carry);
            if(finalHead == NULL) {
                finalHead = newNode;
                finalTail = newNode;
            } else {
                finalTail->next = newNode;
                finalTail = newNode;
            }
        }
        
        return finalHead;
    }
    
    ListNode *reverse(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *smallRes = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return smallRes;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        return reverse(addTwoNumbers2(l1, l2));
    }
};