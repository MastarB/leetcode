#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
	{
		vector<vector<int>>ans;
    	for(int i = 0 ;i < n; i++)
    	{
			vector<int>v;
    		for(int j = 0; j < n ;j++)
    		{
    			v.push_back(0);
			}
			ans.push_back(v);
		}
		fill(ans,n,1,0,0);
		return ans;
    }
    
    void fill(vector<vector<int>>& ans, int n, int b, int i, int j)
    {
    	int ii = i;
    	int jj = j;
    	int count = n-1;
    	if(n == 0)return;
    	if(n == 1)
		{
			ans[ii][jj] = b;
			return;
		}
    	while(count--)
    	{
    		ans[ii][jj] = b;
    		jj++;
    		b++;
    	}
    	count = n-1;
    	while(count--)
    	{
    		ans[ii][jj] = b;
    		ii++;
    		b++;
		}
		count = n-1;
    	while(count--)
    	{
    		ans[ii][jj] = b;
    		jj--;
    		b++;
		}
		count = n-1;
    	while(count--)
    	{
    		ans[ii][jj] = b;
    		ii--;
    		b++;
		}
		fill(ans,n-2,b,i+1,j+1);
	}
};
#define si 2
int main()
{
	Solution so;
	vector<vector<int>>ans = so.generateMatrix(si);
	for(int i  = 0; i < si; i++)
	{
		for(int j = 0; j < si; j++)
			cout<<ans[i][j]<<' ';
		cout<<endl;
	}
}
