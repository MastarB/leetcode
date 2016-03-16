class Solution {
public:
    int findMin(vector<int>& nums) 
	{
    	int b = 0; 
    	int e = nums.size()-1;
    	while(e-b > 1)
    	{
    		int m = (b+e)/2;
    		if(nums[m] < nums[e])e = m;
    		else if(nums[m] > nums[b])b = m+1;
		}
		return min(nums[e],nums[b]);
    }
	
};
