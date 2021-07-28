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
    bool isPalindrome(ListNode* head) {
       if(head==NULL || head ->next==NULL)
           return true;
        
        ListNode *slow=head,*fast=head;
        while(fast->next && fast->next->next )
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* d=NULL, *n;
        ListNode* temp=slow->next;
        while(temp!=NULL)
        {
            n=temp->next;
            temp->next=d;
            d=temp;
            temp=n;
        }
        slow->next=d;
        slow=slow->next;
        
        temp=head;
        while(slow!=NULL)
        {
            if(slow->val!=temp->val)
                return false;
            slow=slow->next;
            temp=temp->next;
        }
        return true;
        
    }
};
