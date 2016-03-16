#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
	{
		int l = nums.size()-1;
		k %= (l+1);
        reverse(nums, 0, l-k);
        reverse(nums,l-k+1,l);
        reverse(nums,0,l);
    }
    //be careful with  the index !!
    void reverse(vector<int>& nums, int b, int e)
    {
        if(b < e)
    	for(int i = b; i < (b+e+1)/2; i++)//to avoid the self-swap
    	{
    	//	if(i == b+e-i)cout<<b<<' '<<e<<' '<<i<<endl;
    	/*	nums[i] ^= nums[e-i];
 			nums[e-i] ^= nums[i];
			nums[i] ^= nums[e-i];   */
			nums[i] ^= nums[b+e-i] ^= nums[i] ^= nums[b+e-i];   
    	}
 		return;	
	}
};
#define N 3
#define K 2
int main()
{
	int ints[N]= {1,2,3};
	Solution so;
	vector<int>ans;
	for(int i = 0; i < N; i++)
		ans.emplace_back(ints[i]);
	so.rotate(ans,K);
	for(int i = 0; i < N; i++)
		cout<<ans[i];
}
