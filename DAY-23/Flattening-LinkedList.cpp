class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL)return head;
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->child)
            {
               
             Node* next=temp->next;
            Node* child=flatten(temp->child);
                
                 temp->child=NULL;
                temp->next=child;
               
                child->prev=temp;
                while(child->next!=NULL)
                {
                    child=child->next;
                }
                child->next=next;
                if(next!=NULL)
                {
                    next->prev=child;
                }
                temp=child;
                cout<<temp->val<<" ";
            }
            temp=temp->next;
        }
        
        return head;
    }
};