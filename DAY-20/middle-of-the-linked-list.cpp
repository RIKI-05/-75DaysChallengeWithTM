class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int s=0;
        ListNode *dum = head;
        
        while(dum){
            s++;
            dum = dum->next;
        }
        // cout<<s<<endl;
        if(s%2==0)s++;
        
        s = s/2;
        int k=0;
        dum = head;
        while(dum){
            if(k==s){
                return dum;
            }
            dum = dum->next;
            k++;
            
        }
        
        return NULL;
        
        
    }
};

