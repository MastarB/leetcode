#include<iostream>
#include<vector>
#include<random>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
	{	
		int mindist =2000000000;
		int minsum;
        shuffle(nums);
        sort(nums);
        /* n^2 time-complexity */ 
        for(int i = 0; i <nums.size()-2; i++)
    	{
    		int j= i+1;
			int k = nums.size()-1;
			while(j < k)
			{ 	
				int dist = nums[k]+nums[j]+nums[i]- target;
				if(dist > 0)
				{
					k--;
					if(dist <mindist)
					{
						mindist = dist;
						minsum =dist + target;
					}
				}
				else if (dist < 0)
				{	
					j++;
					if(-1 *dist <mindist)
					{
						mindist = -dist;
						minsum =dist + target;
					}
				}
					
				else
					return target;
		
			}	
		}
		
		return minsum;
		
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

int main()
{
	int ints[4] = {1,1,1,1};
	vector<int>arr;
	int target = 0;
	Solution so;
	for(int i = 0; i < 4; i++)
		arr.push_back(ints[i]);
	cout<< so.threeSumClosest(arr,target);
	system("pause");
}
