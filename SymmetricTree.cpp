class Solution {
public:
    bool isSymmetric(TreeNode* root) 
	{
		if(root == NULL)return true;
        return isMirrorer(root->left,root->right);
    }
    
    bool isMirrored(TreeNode* l, TreeNode* r)
    {
    	if(l == NULL ^ r == NULL)return false;
    	if(l != NULL)
    		return l->val == r->val &&isMirrored(l->left,r->right)&&isMirrored(l->right,r->left);
    	return true;
	}
};
