
class Solution {
public:
    int maxPathSum(TreeNode* root) 
	{
		int max = 0x80000000;	
		maxPathtoRoot(root,max);
        return max;
    }
    
    int maxPathtoRoot(TreeNode* root, int& max)
    {
    	if(root == NULL)return 0;
    	int r = maxPathtoRoot(root->right,max);
        int l = maxPathtoRoot(root->left,max);
        int nmax = root->val+(l>0?l:0)+(r>0?r:0);
        max = max > nmax ? max : nmax;
        if((r>l?r:l) <= 0)return root->val;
        return root->val + (r>l?r:l);
	}
};
