#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) 
	{
		string ans;
        for(int i = 1; i <= n; i++)
        	ans.push_back(i+'0');
        rr(ans,n,k-1);
        return ans;
    }
    
    void rr(string& s, int n, int k)
    {
    	if(n == 1)return;
    	reverse(s,s.size()-n,s.size()-n+k/order(n-1)-1);
    	reverse(s,s.size()-n,s.size()-n+k/order(n-1));
    	rr(s,n-1,k%order(n-1));
	}
	
	void reverse(string& s, int b, int e)
	{
		while(b < e)
		{
			swap(s[b],s[e]);
			b++;
			e--;
		}
	}
    
    int order(int n)
    {
    	if(n == 0)return 1;
    	else return n*order(n-1);
	}
};
#define si 4
int main()
{
	Solution so;
	for(int i= 1; i <=so.order(si); i++)
	cout<<so.getPermutation(si,i)<<endl;;
	
}
