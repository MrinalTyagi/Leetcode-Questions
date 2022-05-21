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
#include<stack>
class Solution {
public:
    
    ListNode *reverse(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *smallRes = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return smallRes;
    }
    
    
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *slow = head, *fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        fast = head;
        slow = slow->next;
        while(slow != NULL) {
            if(slow->val != fast->val) {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};