class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* nhead= head;
        ListNode *a=NULL,*b=NULL;
        while(nhead!=NULL){
            a=nhead->next;
            nhead->next=b;
            b=nhead;
            nhead=a;
        }
        head = b;
        return head;
        
    }
};