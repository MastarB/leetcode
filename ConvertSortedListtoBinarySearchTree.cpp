class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
    	ListNode* p = head;
    	int length = 0;
    	while(p != NULL)
		{
			length++;
			p = p->next;
		}
        return sortedListToBST(head,length);
    }
    
    TreeNode* sortedListToBST(ListNode* head, int length)
	{
		if(length <= 0)return NULL;
		
		ListNode* m = head;
		int mindex = (length-1)/2;
		for(int i = 0; i < mindex; i++)
			m = m->next;
		TreeNode* r = new TreeNode(m->val);
		r->left = sortedListToBST(head,mindex);
		r->right = sortedListToBST(m->next,length-1-mindex);
		return r;
		
	} 
};
