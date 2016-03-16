class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
	{
		bool LtoR = true;
        vector<vector<int>>ans;
        vector<int>level;
        vector<TreeNode*>levelNodes;
        stack<TreeNode*>s;
        if(root == NULL)return ans;
        s.push(root);
        while(!s.empty())
        {
        	TreeNode* p = s.top();
        	
        	if(p->left != NULL&&LtoR)levelNodes.push_back(p->left);
        	if(p->right != NULL)levelNodes.push_back(p->right);
        	if(p->left != NULL&&!LtoR)levelNodes.push_back(p->left);
        	level.push_back(p->val);
        	s.pop();
        	if(s.empty())
        	{
        		LtoR = LtoR ? false : true;
        		ans.push_back(level);
        		for(int i = 0; i < levelNodes.size(); i++)
        			s.push(levelNodes[i]);
        		levelNodes.clear();
        		level.clear();
			}
		}
		return ans;
    }
};
