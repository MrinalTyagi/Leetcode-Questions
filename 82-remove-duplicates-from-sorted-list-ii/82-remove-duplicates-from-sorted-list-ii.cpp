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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head, *prev = NULL;
        unordered_map<int, int> s;
        while(temp != NULL) {
            s[temp->val]++;
            temp = temp->next;
        }
        
        while(head != NULL && s.count(head->val) > 0 && s[head->val] > 1) {
            head = head->next;
        }
        
        if(head == NULL) {
            return head;
        }
        temp = head->next; 
        prev = head;
        while(temp != NULL) {
            if(s.count(temp->val) > 0 && s[temp->val] > 1) {
                prev->next = (temp->next == NULL) ? NULL : temp->next;
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        
        
        return head;
        
        
        
        
    }
};