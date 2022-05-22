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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || right <= left) {
            return head;
        }
        
        stack<int> s;
        ListNode *temp = head;
        int count = 1;
        while(temp != NULL) {
            if(count >= left && count <= right) {
                s.push(temp->val);
            } 
            temp = temp->next;
            count++;
        }
        count = 1;
        temp = head;
        while(temp != NULL) {
            if(count >= left && count <= right) {
                temp->val = s.top();
                s.pop();
            }
            temp = temp->next;
            count++;
        }
        return head;
    }
};