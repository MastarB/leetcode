class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
	{
        return buildTreeWithIndex(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    
    TreeNode* buildTreeWithIndex(vector<int>& in, int i1, int i2, vector<int>& post, int po1, int po2)
    {
    	if(i1 > i2)return NULL;
    	int index = find(in,i1,i2,post[po2]);
    	TreeNode* p = new TreeNode(post[po2]);
    	p->left = buildTreeWithIndex(in,i1,index-1,post,po1,po1+index-i1-1);
    	p->right = buildTreeWithIndex(in,index+1,i2,post,po1+index-i1,po2-1);
	}
	
	int find(vector<int>& in, int i1, int i2,int valpo2)
	{
		for(int i = i1; i <= i2; i++)
			if (in[i] == valpo2)return i;
		return -1;
	}
};
