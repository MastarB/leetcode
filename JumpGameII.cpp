#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) 
    {
    	int i = 0;
    	int jump = 0;
    	int p = 0;
    	int nextp = 0;
        while(i != nums.size()-1)
        {
        	nextp = nextp > (i+nums[i])?nextp : (i+nums[i]);
        	if(i == p )
			{
        		jump++;
				p = nextp;
				nextp = 0;	
			}
			i++;
		}
		return jump;	
    }
    
};

int main()
{
	int a[5]={2,3,1,1,4};
	vector<int> ans;
	int n= 5;
	while(n--)
		ans.push_back(a[5-n]);
	Solution so;
	cout<<so.jump(ans);
}
