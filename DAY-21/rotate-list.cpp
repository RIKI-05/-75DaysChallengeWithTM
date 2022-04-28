class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0) return head;
        ListNode* curr=head;
        int count=1;
        while(curr->next!=nullptr){
            curr=curr->next;
            count++;
        }
        curr->next=head;          
        k=k%count;
        k=count-k;
        while(k--){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=nullptr;
        return head;
    }
};