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
    vector<int> preorderTraversal(TreeNode* root) 
    {
    	vector<int>ans;
    	if(root == NULL)return ans;
    	stack<TreeNode*>stk;
    	stk.push(root);
    	ans.push_back(root->val);
    	while(!stk.empty())
    	{
    		TreeNode* p = stk.top()->left;
    		
    		while(p != NULL)
    		{
    			ans.push_back(p->val);
    			stk.push(p);
    			p = p->left;
			}
			while(!stk.empty()&&stk.top()->right == NULL)stk.pop();
			if(!stk.empty())
			{
				p = stk.top()->right;
				stk.pop();
				ans.push_back(p->val);
				stk.push(p);
			}
		}
		return ans;
    }
};
