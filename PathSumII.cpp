class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
	{
        vector<vector<int>>ans;
        vector<int>acc;
        getAllPathSum(root,sum,acc,ans);
        return ans;
    }
    
    void  getAllPathSum(TreeNode* root,int sum, vector<int>& acc,vector<vector<int>>& ans)
    {
    	if(root == NULL)return;
    	acc.push_back(root->val);
		if(root->left == NULL && root->right == NULL)
		{	if(sum == root->val)
				ans.push_back(acc);
		}
		else 
		{
			getAllPathSum(root->left,sum-root->val,acc,ans);
			getAllPathSum(root->right,sum-root->val,acc,ans);
		}
		acc.pop_back();
	}
};
