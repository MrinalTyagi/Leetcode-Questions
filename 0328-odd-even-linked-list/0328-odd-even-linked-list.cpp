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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        ListNode *ho = NULL, *he = NULL, *to = NULL, *te = NULL;
        ListNode *temp = head;
        int count = 0;
        while(temp != NULL) {
            if(count % 2 == 1) {
                if(he == NULL) {
                    he = temp;
                    te = temp;
                } else {
                    te->next = temp;
                    te = temp;
                }
            } else {
                if(ho == NULL) {
                    ho = temp;
                    to = temp;
                } else {
                    to->next = temp;
                    to = temp;
                }
            }
            temp = temp->next;
            count++;
        }
        if(ho == NULL) {
            return he;
        }
        if(he == NULL) {
            return ho;
        }
        te->next = NULL;
        to->next = he;
        return ho;
    }
};