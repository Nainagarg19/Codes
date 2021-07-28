/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB== NULL)
            return NULL;
        ListNode *first=headA, *second= headB;
        while(first!=second)
        {
            if(first==NULL)
                first=headB;
            else
                first=first->next;
            if(second== NULL)
                second=headA;
            else
                second=second->next;
        }
        return first;
        
    }
};
