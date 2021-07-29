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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
            return head;
        ListNode *temp=head,*pre=head,*start;
        int c=0;
        while(temp)
        {
            temp=temp->next;
            c++;
        }
        temp=head;
        for(int i=1;i<=k%c;i++)
        {
            temp=temp->next;
        }
        while(temp->next!=NULL)
        {
            temp=temp->next;
            pre=pre->next;
        }
        temp->next=head;
        start=pre->next;
        pre->next=NULL;
        
        return start;
    }
};
