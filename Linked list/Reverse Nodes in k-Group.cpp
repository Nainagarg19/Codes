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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || k==1)
            return head;
        ListNode *dummy= new ListNode(0);
        dummy->next=head;
        ListNode *cur=dummy,*nex, *pre=dummy,*temp=head;
        int count=1,i=0;
        while(temp->next!=NULL)
        {
            count++;
            temp=temp->next;
        }
        while(count>=k)
        {
            count-=k;
            cur=pre->next;
            nex=cur->next;
            for(i=1;i<k;i++)
            {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;                
            }
            pre=cur;
        }        
        return dummy->next;
    }
};