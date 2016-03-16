class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
    	if(nums.size() == 1)return 0;
        int m = rand()%nums.size();
        int b = m;
        while(b < nums.size())
        {
        	if(b == 0&& nums[b]>nums[b+1])return b;
			else if(b == nums.size()-1&& nums[b] >nums[b-1])return b;
			else if(b != 0&& b != nums.size()-1&& nums[b]> nums[b+1]&&nums[b-1]<nums[b])return b;
			else b++;
		}
		b = 0;
		while(b < m)
        {
        	if(b == 0&& nums[b]>nums[b+1])return b;
			else if(b == nums.size()-1&& nums[b] >nums[b-1])return b;
			else if(b != 0&& b != nums.size()-1&& nums[b]> nums[b+1]&&nums[b-1]<nums[b])return b;
			else b++;
		}	
    }
};
