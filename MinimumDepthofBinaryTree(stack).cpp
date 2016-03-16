class Solution {
public:
    int minDepth(TreeNode* root) 
    {
    	if(root == NULL)return 0;
    	int dep = 1;
        queue<TreeNode*>q;
        q.push(root);
        while(true)
        {
        	int l = q.size();
        	for(int i = 0; i < l; i++)
        	{
        		if(q.front()->left == NULL && q.front()->right == NULL)return dep;
				if(q.front()->left != NULL)q.push(q.front()->left);
				if(q.front()->right != NULL)q.push(q.front()->right);
				q.pop();
			}
			dep++;
		}
    }
};
