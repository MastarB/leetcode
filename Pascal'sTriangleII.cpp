#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int>ans;
        ans.push_back(1);
		for(int i = 1; i <= rowIndex; i++)
		{
			int former = ans[0];
			for(int j = 1; j <= i-1; j++)
			{
				int tmp = ans[j-1]+ans[j];
				ans[j-1] = former;
				former = tmp;
			}
			ans[i-1] = former;
			ans.push_back(1);
		}
		return ans;
		    
    }
};

int main()
{
	Solution so;
	vector<int>ans(so.getRow(3));
	for(int i = 0; i < ans.size(); i++)
	cout<< ans[i];
}
