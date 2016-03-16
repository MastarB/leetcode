#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int> >ans;
        vector<int>acc;
        permute(nums,acc,ans,0);
        return ans;
    }
    void permute(vector<int>& nums, vector<int>&acc, vector<vector<int> >&ans, int index)
    {
    	if(index == nums.size())
    	{	
    	    ans.push_back(acc);
    	    return;
    	}
    	//not change the position of nums[i]
    	acc.push_back(nums[index]);
    	permute(nums,acc,ans,index+1);
    	acc.pop_back();
    	for(int i = index + 1; i<nums.size();i++)
    	{
    		if(nums[i] != nums[index])
    		{
				swap(nums[i],nums[index]);
				acc.push_back(nums[index]);
    			permute(nums,acc,ans,index+1);
    			acc.pop_back();
    			swap(nums[i],nums[index]);
    		}
		}
	}
};


