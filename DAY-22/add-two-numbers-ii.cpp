class Solution {
public:
    ListNode* reverse(ListNode*head){
        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* nex = NULL;
        
        while(curr){
            nex = curr->next;
            curr->next = pre;
            pre=curr;
            curr = nex;
             
        }
        head = pre;
        return head;

    }
    
     void insert(ListNode* &start,ListNode* &end,int val){
        ListNode *curr= new ListNode(val) ;
        if(start==NULL){
            start=curr;
            end=curr;
        }
        else{
            end->next=curr;
            end=curr;
        }
    }
    
   ListNode* add(ListNode *l1,ListNode *l2){
        int carry=0;
        ListNode *start=NULL,*end=NULL;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int val1=0;
            if(l1!=NULL){
                val1=l1->val;
            }
            int val2=0;
             if(l2!=NULL){
                val2=l2->val;
            }
            int sum=val1+val2+carry;
            int digit=sum%10;
            insert(start,end,digit);
            carry=sum/10;
            if(l1!=NULL){
                l1=l1->next;
            }
             if(l2!=NULL){
                l2=l2->next;
            }
        }
        return start;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode* ans = add(l1,l2);
        ans = reverse(ans);
        return ans;
    }
};