class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums,int b, int e)
	{
		if(e < b)return NULL;
		int m = (b+e)/2;
		TreeNode*p = new TreeNode(nums[m]);
		p->left = sortedArrayToBST(nums,b,m-1);
		p->right = sortedArrayToBST(nums,n+1,e);
		return p;
	} 
};
