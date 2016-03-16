#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
	{
		auto backup = dungeon;
		int rb = backup.size()-1;
		int cb = backup[0].size()-1;
		if(backup[rb][cb] > 0)backup[rb][cb] = 0;
		if(rb > 0)
			for(int i = rb-1; i >= 0; i--)
				backup[i][cb] = backup[i][cb]+backup[i+1][cb] > 0 ? 0 : backup[i][cb]+backup[i+1][cb];
		if(cb > 0)
			for(int j = cb-1; j >= 0; j--)
				backup[rb][j] = backup[rb][j]+backup[rb][j+1] > 0 ? 0 : backup[rb][j]+backup[rb][j+1]; 
		if(rb > 0 && cb > 0)
		{
			for(int i = rb-1; i >= 0; i--)
				for(int j = cb-1; j >= 0; j--)
				{
					int de = max(backup[i+1][j],backup[i][j+1])+backup[i][j];
					backup[i][j] = de > 0 ? 0 : de;
				}
		}
		return backup[0][0] == 0?1:-backup[0][0]+1;
    }
};
#define r 3
#define c 3
int main()
{
	Solution so;
	vector<vector<int>>d;
	char a[r][c] = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
	for(int i = 0; i < r; i++)
	{
		vector<int>t;
		for(int j = 0; j < c; j++)
			t.push_back(a[i][j]);
		d.emplace_back(move(t));
	}
	cout<<so.calculateMinimumHP(d);
}
