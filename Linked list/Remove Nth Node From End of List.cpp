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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     
        ListNode *l1=head, *start=new ListNode(),*l3;
        start->next=head;
        l3=start;
        for(int i=1;i<n;i++)
        {
            l1=l1->next;
        }
        while(l1->next!=NULL)
        {
            l3=l3->next;
            l1=l1->next;
        }
        l3->next=l3->next->next;
        return start->next;
    }
};
