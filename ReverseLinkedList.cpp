class Solution {
public:
    ListNode* reverseList(ListNode* head) 
	{
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur != NULL)
        {
        	ListNode* tmp = cur->next;
        	cur->next = prev;
        	prev = cur;
        	cur = tmp;
		}
		return prev;
    }
};
