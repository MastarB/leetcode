#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int uniquePaths(int m, int n) 
	{
    	vector<vector<int>>table;
		for(int i = 0; i < m; i++)
		{
    		vector<int>v;
			for(int j = 0; j < n; j++)
				v.push_back(1);
			table.push_back(v);		  	
		}
		for(int i = 1; i < m; i++)
			for(int j = 1; j < n; j++)
				table[i][j] = table[i-1][j]+table[i][j-1];
		return table[m-1][n-1];   
    }
};

int main()
{
	Solution so;
	cout<<so.uniquePaths(3,7);
}
