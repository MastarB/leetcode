#include<vector>
#include<utility>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
	{
		vector<int>ans;
        vector<int>indeg(numCourses);
        vector<vector<int>>tab(numCourses);
        for(auto& i :indeg)
        	i = 0;
        for(auto& i :prerequisites)
        {
        	tab[i.second].push_back(i.first);
        	indeg[i.first]++;
        }
        queue<int>que;
        for(int i = 0; i < indeg.size(); i++)
        	if(indeg[i] == 0)que.push(i);
		int getOut = 0;
		while(!que.empty())  
        {
        	int t = que.front();
        	for(auto i: tab[t])
        		if(--indeg[i] == 0)
					que.push(i);
			que.pop();
			++getOut;
			ans.push_back(t);
		}
		
		if(getOut == numCourses)return ans;
		return vector<int>();
    }
};

