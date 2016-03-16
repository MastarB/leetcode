class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int bound = findBound(nums,0,nums.size()-1);
        if(bsearch(nums,0,bound)||bsearch(nums,bound+1,nums.size()-1))return true;
        return false;
    }
    
    int findBound(vector<int>& nums, int b, int e)
    {
    	int m = (b+e)/2;
    	if(e-b > 1)
    	{
			if(nums[b] == nums[e] && nums[m] == nums[b])
    		{
    			bool left = findDiffer(nums,b,m);
				bool right = findDiffer(nums,m+1,e);
				if(!left&&!right)return e;
				else if(left)return findBound(nums,b,m);
				else findBound(nums,m+1,e);
			}
			else
			{
				if(nums[m] <= nums[e])return findBound(nums,b,m-1);
				if(nums[m] >= nums[b])return findBound(nums,m,e); 
			}
		}
		else
		{
			return nums[e] > nums[b] ?e : b;
		}	
	}
};
