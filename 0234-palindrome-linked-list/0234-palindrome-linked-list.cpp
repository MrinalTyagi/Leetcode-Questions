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
    
    ListNode *reverse(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *rev = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL) {
            return true;
        }
        ListNode *fast = head->next, *slow = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
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