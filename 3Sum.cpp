#include<iostream>
#include<set>
#include<utility>
#include<vector>
#include<random>

using namespace std;
typedef set<pair<int,pair<int,int>>> fuck;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
	{	
		fuck ansset;
		vector<vector<int> >ans;
		if(nums.size()<3)return ans;
        shuffle(nums);
        
        sort(nums);
        /* n^2 time-complexity */ 
        for(int i = 0; i <nums.size()-2; i++)
    	{
    		if(nums[i] > 0)break;
    		int j= i+1;
			int k = nums.size()-1;
			while(j < k)
			{
				if(nums[k]+nums[j]>-nums[i])k--;
				else if (nums[k]+nums[j]<-nums[i])j++;
				else
				{
					ansset.insert(make_pair(nums[i],make_pair(nums[j],nums[k])));
					j++;
					k--;
				}
		
			}		
		}
		for(fuck::iterator i = ansset.begin(); i != ansset.end(); i++)
		{
			vector<int>temp;
			temp.push_back((*i).first);
			temp.push_back((*i).second.first);
			temp.push_back((*i).second.second);
			ans.push_back(temp);
		}
		return ans;
		
    }
/* TLE
    void sort (vector<int>& nums)
    {
    	for(int i = 0; i < nums.size()-1; i++)
    	{
    		for(int j = 0; j<nums.size()-i-1; j++)
    		{
    			if(nums[j]>nums[j+1])
    			{
    				int temp = nums[j];
    				nums[j] = nums[j+1];
    				nums[j+1] = temp;
				}
			}
		}
		for(int i = 0; i < nums.size(); i++)
			cout<<nums[i]<<' ';
	}
	*/
	void sort (vector<int>& nums)
    {
    	quicksort(nums,0,nums.size()-1);	
    }
    
    void quicksort(vector<int>& nums,int b,int e)
    {
    	if(e>b)
    	{
    	   int p = partition(nums,b,e);
    	   quicksort(nums,b,p-1);
    	   quicksort(nums,p+1,e);
		}
	}
	
	int partition(vector<int>& nums, int b, int e)
	{
		int i =b+1;
		int j = e;
		int pivot = nums[b];
		while (i <= j)
		{
			if(nums[i] >pivot)
			{
				swap(nums[i],nums[j]);
				j--;
			}
			else i++;
		}
		swap(nums[b],nums[i-1]);
		return i-1;
	}
    
	void shuffle(vector<int>&nums)
	{
		
		for(int i = 0; i < nums.size(); i++)
		{
			swap(nums[i],nums[rand()%(i+1)]);
		}
	}
};
