#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums)
	{
    	if(nums.size() < 2)return nums.size();
    	int guard = 1900000000;
    	int newLength = 0;
    	for(vector<int>::iterator i = nums.begin(); i != nums.end();)
    		if(guard != *i)
    		{
    			newLength++;
    			guard = *i;
    			i++;
			}
			else i = nums.erase(i);
		return newLength;
    }
};

int main()
{
	Solution so;
	vector<int>nums;
	nums.push_back(1);	nums.push_back(1);	nums.push_back(2);
	cout<< so.removeDuplicates(nums);
}
