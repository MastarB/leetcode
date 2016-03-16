class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
    	if(nums.size()<2)return 0;
    	for(int j = 0; j <= 30; j++)
    	{
    		vector<vector<int>>list;
			for(int i = 0; i < 2 ; i++)
				list.emplace_back(vector<int>());
			for(int n = 0; n < nums.size(); n++)
				list[(nums[n]>>j)&0x00000001].push_back(nums[n]);
			int fuck = 0;
			for(int i = 0; i < 2; i++)
				for(int n = 0; n < list[i].size(); n++)
			 		nums[fuck++] = list[i][n];
		}
		int max = 0;
		for(int i = 1; i < nums.size(); i++)
			max = max >= nums[i]-nums[i-1]? max :nums[i]-nums[i-1];
		return max;
    }
};
