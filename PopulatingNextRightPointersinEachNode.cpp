class Solution {
public:
    void connect(TreeLinkNode* root) 
	{
        queue<TreeLinkNode*>que;
        if(root != NULL)
        que.push(root);
        while(!que.empty())
        {
        	int n = que.size();
        	TreeLinkNode* former = que.front();
        	for(int i = 0; i < n; i++)
        	{
        		if(que.front()->left != NULL)
        			que.push(que.front()->left);
        		if(que.front()->right != NULL)
        			que.push(que.front()->right);
				if(i > 0)
				{
					former->next = que.front();
					former = que.front();
				}
				que.pop();
			}
		}
    }
};
