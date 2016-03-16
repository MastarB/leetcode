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
    vector<int> postorderTraversal(TreeNode* root) 
	{
		vector<int>ans;
		if(root == NULL)return ans;
        stack<TreeNode*>stk;
        stack<TreeNode*>stkR;
        stk.push(root);
        stkR.push(NULL);
        while(!stk.empty())
        {
        	TreeNode* p = stk.top()->left;
        	while(p != NULL)
        	{
        		stk.push(p);
        		p = p->left;
        	}
        	while(!stk.empty())
        	{
        		if(stk.top()->right == NULL)
        		{
        			ans.push_back(stk.top()->val);
        			stk.pop();
				}
				else if(stk.top() == stkR.top())
				{
					ans.push_back(stk.top()->val);
					stkR.pop();
        			stk.pop();
				}
				else
				{
					stkR.push(stk.top());
					stk.push(stk.top()->right);
					break;
				}
			}
		}
    }
};
