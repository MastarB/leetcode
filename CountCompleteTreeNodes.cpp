#include<stack>
#include<cstdlib>
#include<iostream>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

using namespace std;

class Solution {
public:
	/*
    int countNodes(TreeNode* root) 
	{
    	int h = getHeight(root);
    	stack<TreeNode*>stk;
    	stack<int>lstk;
		int count = 0;
		TreeNode *p = root;
		do
		{
			int l = 0;
			while(p != NULL)
			{
				stk.push(p);
				stkl.push(++l);
				p = p->left;
			}
			if(stk.empty())break;
			p = stk.top();
			l = lstk.top();
			if(l == h)count++;
			else break;
			
			
		}while();
	   
    }
    */
    int countNodes(TreeNode* root) 
	{
    	int count = 0;
    	int h = getHeight(root);
    	if(h != getHeightFromRight(root))
    	{
    		while(true)
    		{
    			count *= 2;
    			int hl = getHeight(root->left);
    			int hr = getHeight(root->right);
    			if(hl == 1)
    			{
    				count += (hr == hl? 2 : 1);
    				break;
				}
    			else if(hl == hr)
    			{
					count += 1;
					root = root->right;
				}
				else
					root = root->left;
			}
			h -= 1;//exclude the last level of nodes
		}
		cout<<count<<endl;
		return count + PowWith2(h) - 1;
    }
    
    int PowWith2(int i)
    {
    	int c = 1;
    	int mul = 2;
    	while(i != 0)
    	{
    		if(i%2 == 1)
    			c *= mul;
    		mul *= 2;
    		i /= 2;	 
		}
		return c;
	}
    
    int getHeight(TreeNode* root)
    {
    	int i = 0;
    	while(root != NULL)
    	{
    		++i;
    		root = root->left;
		}
		return i;
	}
	
	int getHeightFromRight(TreeNode* root)
	{
		int i = 0;
    	while(root != NULL)
    	{
    		++i;
    		root = root->right;
		}
		return i;
	}
};

int main()
{
	TreeNode* p = new TreeNode(1);
	TreeNode* root = p;
	p->left = new TreeNode(2);
	p->right = new TreeNode(3);
	p = p->left;
	p->left = new TreeNode(4);
	p->right = new TreeNode(5);
	Solution so;
	cout<<so.countNodes(root);
}
