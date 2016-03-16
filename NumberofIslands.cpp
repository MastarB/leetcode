#include<set>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.size()==0||grid[0].size() == 0)return 0;
    	set<pair<int,int>>sets;
    	int rb = grid.size();
    	int cb = grid[0].size();
    	for(int i = 0; i < rb; i++)
    		for(int j = 0; j < cb; j++)
    			if(grid[i][j] == '1')sets.insert(make_pair(i,j));	
    
    	int count = 0;
    	while(!sets.empty())
    	{
    		queue<pair<int,int>>que;
    		auto g = sets.begin();
    		sets.erase(g);
    		grid[g->first][g->second] = '0';
    		que.push(*g);
    		
    		count++;
    		while(!que.empty())
    		{
    			auto t = que.front();
    			if(t.first > 0)
    			{
    				auto tt = make_pair(t.first-1,t.second);
					if(grid[tt.first][tt.second] == '1')
					{
						sets.erase(tt);
						grid[tt.first][tt.second] = '0';
						que.push(tt);
					}
				}
    			if(t.first < rb-1)
    			{
    				auto tt = make_pair(t.first+1,t.second);
					if(grid[tt.first][tt.second] == '1')
					{
						sets.erase(tt);
						grid[tt.first][tt.second] = '0';
						que.push(tt);
					}
				}
    			if(t.second > 0)
    			{
    				auto tt = make_pair(t.first,t.second-1);
					if(grid[tt.first][tt.second] == '1')
					{
						sets.erase(tt);
						grid[tt.first][tt.second] = '0';
						que.push(tt);
					}
				}
    			if(t.second < cb-1)
    			{
    				auto tt = make_pair(t.first,t.second+1);
					if(grid[tt.first][tt.second] == '1')
					{
						sets.erase(tt);
						grid[tt.first][tt.second] = '0';
						que.push(tt);
					}
				}
				que.pop();
			}
		}
		return count;
	}
};
