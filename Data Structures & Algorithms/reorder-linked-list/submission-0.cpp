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
    void reorderList(ListNode* head) {

        ListNode* middle = head;
        ListNode* end = head;

        while(end->next && end->next->next){
            middle = middle->next;
            end = end->next->next;
        }

        
        ListNode* prev = nullptr;
        ListNode* curr = middle->next;
        ListNode* next = middle->next;

        middle->next = nullptr;

        while(next){
            next = next->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* revHead = prev;


        while(revHead){
            ListNode* next1 = head->next;
            ListNode* next2 = revHead->next;

            head->next = revHead;
            revHead->next = next1;

            head = next1;
            revHead = next2;

            next1 = next1->next;
            next2 = next2->next;

        }


    }
};
