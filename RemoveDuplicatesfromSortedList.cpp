class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
         
         ListNode* p = head;
         while(p != NULL)
         {
         	ListNode* g = p->next;
         	while(g != NULL && g->val == p ->val)
         	{
         		ListNode* temp = g;
         		g = g->next;
         		delete(temp);
			}
			p->next = g;
			p = g;
		 }
		 return head;
    }
};
