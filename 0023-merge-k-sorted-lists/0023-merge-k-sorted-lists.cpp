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

struct mycomp {
    bool operator()(ListNode *first, ListNode *second) {
        return first->val > second->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL, *tail = NULL;
        priority_queue<ListNode *, vector<ListNode *>, mycomp> pq;
        for(auto x: lists) {
            if(x != NULL) {
                pq.push(x);
            }
        }
        if(pq.size() == 0) {
            return head;
        }
        while(!pq.empty()) {
            ListNode *top = pq.top();
            pq.pop();
            if(head == NULL) {
                head = top;
                tail = top;
            } else {
                tail->next = top;
                tail = top;
            }
            top = top->next;
            if(top != NULL) {
                pq.push(top);
            }
        }
        tail->next = NULL;
        return head;
    }
};