class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
        return buildTreeWithIndex(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    
    TreeNode* buildTreeWithIndex(vector<int>& pre, int p1, int p2, vector<int>& in, int i1, int i2)
    {
    	if(i1 > i2)return NULL;
    	int index = find(in,i1,i2,pre[p1]);
    	TreeNode* p = new TreeNode(pre[p1]);
    	p->left = buildTreeWithIndex(pre,p1+1,p1+index-i1,in,i1,index-1);
    	p->right = buildTreeWithIndex(pre,p1+index-i1+1,p2,in,index+1,i2);
	}
	
	int find(vector<int>& in, int i1, int i2,int valp1)
	{
		for(int i = i1; i <= i2; i++)
			if (in[i] == valp1)return i;
		return -1;
	}
};
