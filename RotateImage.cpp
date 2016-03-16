#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
	{
    
		int l = matrix.size();
		for(int i = 0; i < (l+1)/2;i++)
		for(int j = 0;j < l/2; j++)
		{
			int x =i;
			int y =j;
			int temp = 0;
			int temp2;
			int tempx;
			for(int n = 0;n < 5; n++)
			{
				temp2 = matrix[x][y];
				matrix[x][y] = temp;
				temp = temp2;
				tempx =x;
				x = y;
				y = l-1-tempx;		
			}
		}
	}
};
