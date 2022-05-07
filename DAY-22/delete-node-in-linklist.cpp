class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;   // O(1)
        node->next=node->next->next; 
    }
};