/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp!=NULL)
        {
            Node *dummy= new Node(temp->val);
            dummy->next=temp->next;
            temp->next=dummy;
            temp=dummy->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            if(temp->random !=NULL)
                temp->next->random= temp->random->next;
            temp= temp->next->next;
        }
        
        temp=head;
        Node *copied=new Node(0);
        Node* copy=copied;
        Node *pre;
        while(temp!=NULL)
        {
            pre=temp->next->next;
            copy->next=temp->next;
            temp->next=pre;
            copy=copy->next;
            temp=pre;
            
        }
        return copied->next;
    }
};
