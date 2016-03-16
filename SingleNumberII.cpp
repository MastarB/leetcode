class Solution {
public:
    int singleNumber(vector<int>& nums) 
	{
        int acc = 0;
        int odd = 0;
        for(int i = 0; i < nums.size(); i++)
        {
        	acc |= nums[i]&odd;
			odd ^= nums[i];
			int t = acc&odd;
			odd &= ~t;
			acc &= ~t;
		}
		return odd;
    }
};
