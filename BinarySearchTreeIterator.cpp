/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) 
	{
        nodeVals.clear();
    	fill(nodeVals,root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
	{
        return nodeVals.size() > index;
    }

    /** @return the next smallest number */
    int next() 
	{
        return nodeVals[index++];
    }
    
    void fill(vector<int>& vals, TreeNode* root)
    {
    	if(root == NULL)return;
    	fill(nodeVals,root->left);
    	nodeVals.push_back(root->val);
    	fill(nodeVals,root->right);
	}
private:
	int index = 0;
	vector<int>nodeVals;
};
