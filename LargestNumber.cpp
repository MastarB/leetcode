#include<string>
#include<vector>
#include<iostream>
#include<random>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
    	shuffle(nums);
    	bool fzero = true;
        sort(nums,0,nums.size()-1);
        string buffer("");
        for(int i = 0; i < nums.size(); i++)
        {
        	if(nums[i] == 0&& fzero);
        	else
        	{
    			buffer.append(I2String(nums[i]));
    			fzero = false;
    		}
		}
		if(fzero)buffer.push_back('0');
        return buffer; 
    }
    
    void shuffle(vector<int>& n)
    {
    	for(int i = 0; i < n.size(); i++)
    	 swap(n[i],n[rand()%(i+1)]);
	}
	
	void sort(vector<int>& n, int b, int e)
	{
		if(b < e)
		{
			int p = partition(n,b,e);
			sort(n,b,p-1);
			sort(n,p+1,e);
		}
	}
	
	int partition(vector<int>&n, int b, int e)
	{
		int count = b;
		for(int i = b; i < e; i++)
			if(isCombineLessThan((long long)n[e],(long long)n[i]))
				swap(n[count++],n[i]);
		swap(n[e],n[count]);
		return count;
	}
	
	bool isCombineLessThan(long long a, long long b)
	{
		long long aa;
		long long bb;
		int shift = 10;
		while(a/shift != 0)
			shift *= 10;
		bb = b*shift + a;
		
		shift = 10;
		while(b/shift != 0)
			shift *= 10;
		aa = a*shift + b;
		cout<<aa<<' '<<bb<<endl;
		return aa < bb;
	}
	
	string I2String(int a)
	{
		string ans("");
		if(a == 0)ans.push_back('0');
		while(a != 0)
		{
			ans.push_back(a%10+'0');
			a /= 10;
		}
		for(int i = 0; i < ans.size()/2; i++)
			swap(ans[i],ans[ans.size()-i-1]);
		return ans;
	}
    
};
#define N 2
int main()
{
	vector<int>v;
	int ints[N] = {0,0};
	for(int i = 0; i < N; i++)
		v.push_back(ints[i]);
	Solution so;
	cout<<so.largestNumber(v);
}
