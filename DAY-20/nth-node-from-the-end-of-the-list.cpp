class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dum = head;
        int s=0;
        
        while(dum){
            s++;
            dum = dum->next;
        }
        if(s==n) return head->next;
        n = n%s;
         n=s-n;
        int p=1;
        ListNode*temp;
        temp =head;
        while(p<n){
            temp=temp->next;
            p++;
        }
        temp->next=temp->next->next;
        return head;
    }
};

