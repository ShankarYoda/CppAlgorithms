/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    int sizeOfLinkedList(ListNode *&head)
    {
        int size = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int size1 = sizeOfLinkedList(headA);
        int size2 = sizeOfLinkedList(headB);
        int diff;

        ListNode *temp1;
        ListNode *temp2;

        if (size1 > size2)
        {
            diff = size1 - size2;
            temp1 = headA;
            temp2 = headB;
        }
        else
        {
            diff = size2 - size1;
            temp1 = headB;
            temp2 = headA;
        }
        while (diff--)
        {
            temp1 = temp1->next;
        }
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1 == temp2)
                return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};