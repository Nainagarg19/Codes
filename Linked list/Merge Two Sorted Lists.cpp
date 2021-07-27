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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL )
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *first=l1,*second=l2;
        ListNode *d,*d2;
        if(first->val<=second->val)
        {   
            d=first;
            first=first->next;
        }
        else
        {
            d=second;
            second=second->next;
        }
        d2=d;
        while(first!=NULL && second!=NULL)
        {
            if(first->val <=second->val)
            {
                d2->next=first;
                d2=first;
                first=first->next;
            }
            else
            {
                d2->next= second;
                d2=second;
                second =second->next;
            }                
        }
        if(first!=NULL)
        {
            d2->next=first;
        }
        else
            d2->next=second;
        return d;
    
    }
};
