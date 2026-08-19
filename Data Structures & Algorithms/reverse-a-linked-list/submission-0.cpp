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
    ListNode* reverseList(ListNode* head) {
        
        if(!head) return head;
        if(!head->next) return head;

        ListNode* prv = nullptr;
        ListNode* cur = head;
        ListNode* nxt = head->next;

        while(nxt){
            cur->next = prv;
            prv = cur;
            cur = nxt;
            nxt = nxt->next;
        }

        cur->next = prv;

        return cur;

    }
};
