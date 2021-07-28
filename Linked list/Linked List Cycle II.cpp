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
    ListNode *detectCycle(ListNode *head) {
        ListNode *ans=NULL;
        if(head==NULL || head->next==NULL)
            return ans;
        ListNode *pre=head,*slow=head,*fast=head;
        
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast )
            {   
                while(pre!=slow && fast !=NULL)
                {
                    pre=pre->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return ans;
    }
};
