/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
	{
		vector<int>ans;
        queue<TreeNode*>que;
        if(root != NULL)que.push(root);
        while(!que.empty())
        {
        	int l = que.size();
        	ans.push_back(que.front()->val);
        	for(int k = 0; k < l; k++)
        	{
        		if(que.front()->right != NULL)que.push(que.front()->right);
        		if(que.front()->left != NULL)que.push(que.front()->left);
        		que.pop();
			}
		}
		return ans;
    }
};
