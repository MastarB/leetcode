#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
	{
		vector<pair<int, int>>& e = prerequisites;
		if(e.empty())return true;
		sortBySecondEle(e);
        vector<int>indeg;
		for(int i = 0; i < numCourses; ++i)
			indeg.push_back(0);
		for(int i = 0; i < e.size(); ++i)
			++indeg[e[i].first];
        queue<int>que;
        for(int i = 0; i < numCourses; ++i)
        	if(indeg[i] == 0)que.push(i);
        int getOutofQue = 0;
        while(!que.empty())
        {	
        	
        	int t = que.front();
        	int index = findFirstApprearedBySecondEle(e,t);
        	
        	while(index != -1 && index < e.size() && e[index].second == t)
        	{
        		cout<<index<<endl;
        		indeg[e[index].first]--;
        		if(indeg[e[index].first] == 0)que.push(e[index].first);
        		index++;
			}
			que.pop();
			getOutofQue++;
			
		}
		return getOutofQue == numCourses;
    }
    
    void sortBySecondEle(vector<pair<int, int>>& e)
    {
    	sort(e,0,e.size()-1);
	}
	
	void sort(vector<pair<int, int>>& edge, int b, int e)
	{
		int count = b;
		if(b < e)
		{
			for(int i = b; i < e; i++)
				if(edge[i].second < edge[e].second)swap(edge[i],edge[count++]);
				
			swap(edge[e],edge[count]);
			sort(edge,b,count-1);
		    sort(edge,count+1,e);
		}
		
	}
	int findFirstApprearedBySecondEle(vector<pair<int, int>>& edge, int t)
	{
		int b = 0;
		int e = edge.size()-1;
		while(e-b > 1)
		{
			int m = (b+e)>>1;
			if(edge[m].second < t)b = m +1;
			else if(edge[m].second > t)e = m-1;
			else e = m;
		}
		return  edge[b].second == t ? b : edge[e].second == t ? e : -1;
	}
	
	
};
