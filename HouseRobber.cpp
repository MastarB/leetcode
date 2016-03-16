#define Max(x,y) ((x)>(y))?(x):(y)
class Solution {
public:
    int rob(vector<int>& nums) 
	{
        if(nums.size() == 0)return 0;
        if(nums.size() == 1)return nums[0];
        vector<int>tab;
        tab.push_back(0);
        tab.push_back(nums[0]);
        for(int i = 2; i <= nums.size(); i++)
        	tab.push_back(Max(nums[i-1]+tab[i-2],tab[i-1]));
        return tab[nums.size()];
    }
};
