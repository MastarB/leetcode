#include<vector>
#include<stack>
using namespace std;
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
    	vector<TreeNode*>vp = getPre(root, p);
		vector<TreeNode*>vq = getPre(root, q);
		TreeNode* comm;
		for(int i = 0; i < vp.size(); ++i)
		{
			if(i == 0)
				comm = vp[0]; 
			if(vp[vp.size()-1-i] != vq[vq.size()-1-i])
				return comm;
			else comm = vp[i];	
		}    
    }
    
    vector<TreeNode*> getPre(TreeNode* root, TreeNode* t)
    {
    	vector<TreeNode*>ans;
    	stack<TreeNode*>stk;
    	stack<TreeNode*>stk1;
    	stk1.push(NULL);
    	TreeNode* p = root;
    	while(p != NULL)
    	{
    		while(p != NULL)
    			stk.push(p);
    		p = stk.top();
    		while(p == stk1.top() || p->right == NULL)
    		{
    			if(p == t)
				{
					for(!stk.empty())
					{
						ans.push_back(stk.top())
						stk.pop();
					}
					return ans;
				}
    			else
    			{
    				stk.pop();
    				if(p == stk1.top())
						stk1.pop();
    				p = stk.top();
    				if(stk1.top() == NULL)
						exit(1);
				}
			}
			stk1.push(p);
			p = p->right;
		}
	}
    
    
};
