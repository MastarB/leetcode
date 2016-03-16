class Solution {
public:
    void flatten(TreeNode* root) 
	{
		if(root != NULL)
        	flattenWithTail(root);
    }
    
    TreeNode* flattenWithTail(TreeNode* root)
	{
		if(root->left == NULL&&root->right == NULL)return root;
		TreeNode* r = root->right;
		if(root->left != NULL)
		{
			TreeNode* ltail = flattenWithTail(root->left);
			root->right = root->left;
			root->left = NULL;
			if(r != NULL)
			{
				ltail->right = r;
				return flattenWithTail(r);
			}
			else return ltail;
		}
		return flattenWithTail(r);
		
	} 
};
