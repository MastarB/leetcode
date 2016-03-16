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
    ListNode* deleteDuplicates(ListNode* head) 
	{
        if(head == NULL)return head;
        ListNode* guard = head;
        ListNode* former = head;
        ListNode* p = head ->next;
        bool shouldDel = false;
        while(p != NULL)
        {
        	if(p->val != guard->val)
        	{
        		if(shouldDel)del(guard,p,former,head);
        		else former = guard;
        		guard = p;
        		shouldDel = false;
			}
			else
			{
				shouldDel = true;
			}
			p = p->next;
		}
		if(shouldDel)del(guard,NULL,former,head);
        return head;
    }
    
    void del(ListNode* g, ListNode* p, ListNode*& f, ListNode*& h)
    {
    	if(g == h)
		{
			h = p;
			f = p;
		}
		else f->next = p;
    	while(g != p)
    	{
    		ListNode* tmp = g;
    		g = g->next;
    		delete(tmp);
		}
	}
};
