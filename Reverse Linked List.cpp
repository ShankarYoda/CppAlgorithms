class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *next = NULL;
        ListNode *prev = NULL;

        while (cur != NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur= next;

        }        
        head = prev;
        return head;
    }
};
