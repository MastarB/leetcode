#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) 
	{
		int e = height.size()-1;
		int maxh = 0;
		int maxindex =0;
		int acc = 0;
		int all = 0;
		for(int i = 0; i <= e; i++)
		{
			if(height[i] > maxh)
			{
				all += acc;
				acc = 0;
				maxh = height[i];
				maxindex = i; 
			}
			else
			{
				acc += maxh - height[i];
			}
		}
		acc = 0;
		maxh =0;
		for(int i = e; i >= maxindex; i--)
		{
			if(height[i] >= maxh)
			{
				all += acc;
				acc = 0;
				maxh = height[i]; 
			}
			else
			{
				acc += maxh - height[i];
			}	
		} 
		return all;  
    }
};

int main()
{
	vector<int>ans;
  int a[12]={0,1,0,2,1,0,1,3,2,1,2,1};
  for(int i = 0; i < 12 ;i++)
  	ans.push_back(a[i]);
	Solution so;
	cout<<so.trap(ans);
	
  
}
