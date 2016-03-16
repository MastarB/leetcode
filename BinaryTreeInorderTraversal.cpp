#include<vector>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 TreeNode* BuildTree(vector<char>& serials)
 {
 	TreeNode* root = new TreeNode(0);
 	queue<TreeNode*>q;
 	q.push(root);
 	int index = 0;
	while(!q.empty()&& index < serials.size())
	{
		if(serials[index] != '#')
		{
			q.front()->val = serials[index]-'0';
			q.front()->left = new TreeNode(0);
			q.front()->right = new TreeNode(0);
			q.push(q.front()->left);
			q.push(q.front()->right);
			q.pop();
		}
		else
		{
			delete q.front();
		}
		index++;
	}
	while(!q.empty())
	{
		delete q.front();
		q.pop();
	}
	return root;
 }

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
	{
		vector<int>ans;
		if(root == NULL)return ans;
		stack<TreeNode*>s;
		TreeNode* p = root;
		s.push(p);
		
        while(!s.empty())
        {
        	while(p->left != NULL)
        	{
        		p = p->left;
        		s.push(p);
			}
			while(!s.empty())
			{
				ans.push_back(s.top()->val);
				if(s.top()->right != NULL)
					break;
				s.pop();
			}
			
			if(!s.empty())
			{
				p = s.top()->right;
				s.pop();
				s.push(p);
			}
		}
		return ans;
    }
};

int main()
{
	vector<int>ans;
	vector<char>s;
	Solution so;
	char ss[4] = {'1','2','#','3'};
	for(int i = 0; i < 4; i++)
		s.push_back(ss[i]);
	TreeNode* root = BuildTree(s);
	ans = so.inorderTraversal(root);
	for(int i = 0; i < ans.size(); i++)
		cout<<ans[i]<<' ';
}
