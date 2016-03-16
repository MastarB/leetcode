#include<vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
	{
		if(obstacleGrid.empty()||obstacleGrid[0].empty()||obstacleGrid[0][0] == 1||obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1)return 0;
		bool blocked = false;
		obstacleGrid[0][0] = 1;
        for(int j = 1; j < obstacleGrid[0].size();j++)
        {
        	if(!blocked)
			{
				if(obstacleGrid[0][j] == 0)obstacleGrid[0][j] = 1;
				else blocked = true;
			}
			if(blocked)obstacleGrid[0][j] = 0;
		}
		blocked = false;
		for(int i = 1; i < obstacleGrid.size(); i++)
		{
			if(!blocked)
			{
				if(obstacleGrid[i][0] == 0)obstacleGrid[i][0] = 1;
				else blocked = true;
			}
			if(blocked)obstacleGrid[i][0] = 0;
		}
		for(int i = 1; i < obstacleGrid.size(); i++)
			for(int j = 1; j < obstacleGrid[i].size(); j++)
			{
				if(obstacleGrid[i][j] == 1)obstacleGrid[i][j] = 0;
				else obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
			}
		return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};

int main()
{
}
