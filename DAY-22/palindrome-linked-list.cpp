class Solution {
public:
    bool isPalindrome(ListNode* head) {
 stack<int>st;
    ListNode* temp=head;
    while(temp!=NULL){
        st.push(temp->val);
        temp=temp->next;
    }
    temp=head;
    while(!st.empty()){
        if(st.top()!=temp->val){
            return false;
        }
        else{
            st.pop();
            temp=temp->next;
        }
        
    }    
       return true;     
    
    }
};