#include<vector>
#include<iterator>
#include<iostream>
#define Min(a,b)  ((a)<(b)?(a):(b))
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
	{
    	if(nums.size() == 0)return 0;
    	int indexb = 0;
    	int indexe = 0;
    	
    	int sum = 0;
    	while(sum < s && indexe < nums.size())
    		sum += nums[indexe++];
    	if(sum < s)return 0;
    	int min = indexe - indexb; 
    	while(indexe <= nums.size())
    	{
    		while(indexb < nums.size() && sum - nums[indexb] >= s )
    		{	
    			sum -= nums[indexb++];
    			min = Min(min,indexe - indexb);
    		}
    		if(indexe == nums.size())break;
    		sum += nums[indexe++];
		}
		
		return min;
    		
    }
};

int main()
{
	int a[]= {2,3,1,2,4,3};
	vector<int>nums(begin(a),end(a));
	Solution so;
	cout<<so.minSubArrayLen(7,nums);
	
}
