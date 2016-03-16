#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
	{
		vector<string>ans;
   		if(nums.size() == 0)
		   return ans;
   		else
		{
			int guard = nums[0];
			for(int i = 1; i < nums.size(); ++i)
			{
				if(nums[i] != nums[i-1]+1)
				{
					if(guard != nums[i-1])
						ans.emplace_back(toString(guard)+"->"+toString(nums[i-1]));
					else
						ans.emplace_back(toString(guard));
					guard = nums[i];
				}
			}
			
			if(guard != nums[nums.size()-1])
				ans.emplace_back(toString(guard)+"->"+toString(nums[nums.size()-1]));
			else
				ans.emplace_back(toString(guard));
			return ans;
				
		}  
    }
    
    string toString(long long n)
    {
    	
    	string s;
    	bool neg = false;
    	if(n == 0)return "0";
    	if(n < 0)
		{
			neg = true;
			n = -n;
		}
    
    	while(n != 0)
    	{
    		s.push_back('0'+n%10);
    		n /= 10;
		}
		if(neg)s.push_back('-');
		int j = 0, k = s.size()-1;
		
		
		while(j < k)
		{
			swap(s[j],s[k]);
			++j;
			--k;
		}
		return s;
	}
};

int main()
{
	vector<int> nums{0,1,2,4,5,7};
	Solution so;
	vector<string>a(so.summaryRanges(nums));
	for(auto& s :a)
	cout<<s<<endl;
}
