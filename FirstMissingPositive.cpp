#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        for(int i = 0; i< nums.size(); i++)
		{	
			int t = i;
			while(nums[t] >= 1 && nums[t] <= nums.size() && nums[t] != nums[nums[t]-1])
				swap(nums[t],nums[nums[t]-1]);
		
		}
		int i;
		for(i = 0; i< nums.size(); i++)
    		if(i+1 != nums[i])return i+1;
    	return i+1;
    }
};
