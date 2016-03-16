#include<stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
	{
		vector<vector<int>>ans;
        vector<int>level;
        vector<TreeNode*>levelNodes;
        queue<TreeNode*>q;
        stack<vector<int> >s; 
        if(root == NULL)return ans;
        q.push(root);
        while(!q.empty())
        {
        	TreeNode* p = q.front();
        	if(p->left != NULL)levelNodes.push_back(p->left);
        	if(p->right != NULL)levelNodes.push_back(p->right);
        	level.push_back(p->val);
        	q.pop();
        	if(q.empty())
        	{
        		s.push(level);
        		for(int i = 0; i < levelNodes.size(); i++)
        			q.push(levelNodes[i]);
        		levelNodes.clear();
        		level.clear();
			}
		}
		while(!s.empty())
		{
			ans.push_back(move(s.top()));
			s.pop();
		}
		return ans;
    }
    
    
};
