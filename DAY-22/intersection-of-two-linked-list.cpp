class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0,m=0;
        ListNode *temp;
        temp=headA;
        
        if(headA==NULL || headB==NULL)return NULL;
        while(temp){
            n++;
            temp = temp->next;
        }
        temp=headB;
        while(temp){
            m++;
            temp = temp->next;
        }
        int diff =0;
        ListNode *p,*q;
        if(n>m){
            diff = n-m;
            p = headA;
            q = headB;
        }
        else{
            diff = m-n;
            p = headB;
            q = headA;
        }
        while(diff--){
            p = p->next;
        }
        
        while(p and q){
            if(p == q) return p;
            p = p->next;
            q = q->next;
        }
        
        return NULL;
    }
};