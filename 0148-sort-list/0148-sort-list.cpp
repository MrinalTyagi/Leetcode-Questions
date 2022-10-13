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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        multimap<int, ListNode *> s;
        ListNode *temp = head;
        while(temp != NULL) {
            s.insert({temp->val, temp});
            temp = temp->next;
        }
        ListNode *headF = NULL;
        ListNode *tailF = NULL;
        for(auto x: s) {
            if(headF == NULL) {
                headF = x.second;
                tailF = x.second;
            } else {
                tailF->next = x.second;
                tailF = x.second;
            }
        }
        tailF->next = NULL;
        return headF;
    }
};