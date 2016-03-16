/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) 
	{
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && slow != NULL && fast->next != NULL)
        {
        	fast = fast->next->next;
        	slow = slow->next;
        	if(fast == slow)
        	{
				while(head != slow)
				{
					head = head->next;
					slow = slow->next;
				} 
        		return head;
        	}
		}
		return NULL;
    }
};
