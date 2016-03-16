#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
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
    	set<int>existed;
    	//not change the position of nums[i]

    	for(int i = index ; i < nums.size();i++)
    	{
    		if(existed.find(nums[i])==existed.end())
    		{
    		    existed.insert(nums[i]);
				swap(nums[i],nums[index]);
				acc.push_back(nums[index]);
    			permute(nums,acc,ans,index+1);
    			acc.pop_back();
    			swap(nums[i],nums[index]);
    		}
		}
	}
};

