class Solution {
public:
    bool isBalanced(TreeNode* root) 
	{
		if(root == NULL)return true;
        int l = height(root->left);
        int r = height(root->right);
        if(l-r == 0 || l-r == 1 || l-r == -1)return isBalanced(root->left) && isBalanced(root->right);
        return false;
    }
    
    int height (TreeNode* root)
    {
    	if(root == NULL)return 0;
    	return max(height(root->left),height(root->right))+1;
	}
};
