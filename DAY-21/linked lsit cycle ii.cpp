class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL or head->next == NULL)
            return NULL;
        ListNode *slow = head, *fast = head;
        int flag = 0;
        while(fast and fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            return NULL;
        else
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
            
    }
};