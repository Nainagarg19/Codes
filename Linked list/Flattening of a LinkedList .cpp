

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/
Node *Merge(Node* a, Node* b)
{
    Node *res= new Node(0);
    Node *temp=res;
    
    
    while(a!=NULL && b!=NULL)
    {
        if(a->data < b->data)
        {
            temp->bottom=a;
            temp=a;
            a=a->bottom;
        }
        else
        {
            temp->bottom=b;
            temp=b;
            b=b->bottom;
        }
    }
    
    if(a)
        temp->bottom=a;
    else
        temp->bottom= b;
        
    return res->bottom;
}
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL)
    return root;
    
    root->next= flatten(root->next);
    
    root=Merge(root, root->next);
    
    return root;
}

