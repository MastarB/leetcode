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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* fakehead = new ListNode(0);
        fakehead->next = head;
        ListNode* prev = fakehead;
        ListNode* cur = head;
        while(cur != NULL)
        {
        	if(cur->val == val)
        	{
        		prev->next = cur->next;
        		delete cur;
        		cur = prev->next;
			}
			else
			{
				cur = cur->next;
				prev = prev->next;
			}
		}
		head = fakehead->next;
		delete fakehead;
		return head;
    }
};
