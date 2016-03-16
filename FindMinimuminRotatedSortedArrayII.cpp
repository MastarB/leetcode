class Solution {
public:
    int findMin(vector<int>& nums) 
	{
        int b = 0;
		int e = nums.size()-1;
		while(e-b > 1)
		{
			int m  = (b+e)>>1;
			if(nums[m] < nums[e])e = m;
			else if(nums[m] > nums[b]&&nums[m] != nums[e])b = m+1;
			else 
			{
				if(nums[m] == nums[b])b++;
				if(nums[m] == nums[e])e--;	
			}
		}
		return min(nums[b],nums[e]); 
    }
};
