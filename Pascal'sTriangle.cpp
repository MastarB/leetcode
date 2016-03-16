class Solution {
public:
    vector<vector<int>> generate(int numRows) 
	{
        vector<vector<int>>ans;
        if(numRows == 0)return ans;
        vector<int>t1;
        t1.push_back(1);
        ans.emplace_back(std::move(t1));
        for(int i = 1; i < numRows; i++)
        {
        	vector<int>tn;
        	for(int j = 0; j <= i; j++)
        	{
        		if(j == 0||j == i)tn.push_back(1);
        		else tn.push_back(ans[i-1][j-1]+ans[i-1][j]);
            } 
    		ans.emplace_back(std::move(tn));
		}
		return ans;
		
    }
};
