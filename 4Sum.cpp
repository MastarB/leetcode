#include<iostream>
#include<set>
#include<vector>
#include<utility>
using namespace std;
typedef  set<pair<pair<int,int>,pair<int,int> > >  fuck;

class Solution {
public:
	
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
    	
    	vector<vector<int>> ans;
    	if(nums.size()<4)return ans;
    	fuck ansset;
    	shuffle(nums);
    	sort(nums);
    	for(int i = 0; i < nums.size()-3; i++)
    	{
    		if(nums[i]>0&&nums[i] > target)break;
    		for(int j = i+1; j < nums.size()-2; j++)
    		{
    			if(nums[j]>0&&nums[i]+nums[j] > target)break;
    			int p = j+1;
    			int q = nums.size()-1;
    			while(p < q)
    			{
    				if(nums[p]+nums[q]+nums[i]+nums[j]>target)
    				q--;
    				else if(nums[p]+nums[q]+nums[i]+nums[j]<target)
    				p++;
    				else 
    				{
    					ansset.insert(make_pair(make_pair(nums[i],nums[j]),make_pair(nums[p],nums[q])));
    					q--;
    					p++;
					}
				}
			}
		}
		
		for(fuck::iterator i = ansset.begin(); i != ansset.end(); i++)
		{
			vector<int>temp;
			temp.push_back((*i).first.first);
			temp.push_back((*i).first.second);
			temp.push_back((*i).second.first);
			temp.push_back((*i).second.second);
			ans.push_back(temp);
		}
		return ans;
		
    }
    
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
	vector<int>ints;
	int n = 8;
	int k[n]= {0,1,5,0,1,5,5,-4};
	
	while(n--)
	ints.push_back(k[n]);
	Solution so;
	vector<vector<int>> ans = so.fourSum(ints,11);
	for(int i = 0 ;i < ans.size(); i++)
	{
		for(int j = 0 ; j < ans[i].size(); j++)
		cout<<ans[i][j]<<' ';
		cout<<endl;
	}
}
