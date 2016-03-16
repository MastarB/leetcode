class Solution {
public:
    int minDepth(TreeNode* root) 
    {
    	if(root == NULL)return 0;
    	minDepth(root,1);
    }
    
    int minDepth(TreeNode* root, int dep)
    {
    	int p1 = root->left == NULL ? -1 : minDepth(root->left,dep+1);
    	int p2 = root->right == NULL ? -1 : minDepth(root->right,dep+1);
    	return p1 == -1 ? p2 == -1?dep:p2 : p2 == -1?p1:min(p1,p2);
	}
};
