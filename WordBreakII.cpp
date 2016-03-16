#include<unordered_set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) 
	{
		int maxl = 0;
		vector<string>ans;
		string acc("");
		queue<int>que;
		
		for(auto i = wordDict.begin(); i != wordDict.end(); i++)
			maxl = maxl < (*i).size()?(*i).size():maxl;
		map<int,vector<int>>edges;
		map<int,vector<int>>fathers;		
		for(int i = 0; i < s.size(); i++)
			for(int j = 1; i+j <= s.size()&& j <= maxl; j++)
				if(wordDict.find(s.substr(i,j)) != wordDict.end())
					edges[i+j].push_back(i);
		bool tags[s.size()];
		for(int i = 0; i <= s.size(); i++)
			tags[i] = false;
		que.push(s.size());
		tags[s.size()] = true;
		while(!que.empty())
		{
			int t = que.front();
			vector<int>& et = edges[t];
			for(int i = 0; i < et.size(); i++)
			{
				fathers[et[i]].push_back(t);
				if(!tags[et[i]])
				{
					tags[et[i]] = true;
					que.push(et[i]);
				}
			}
			que.pop();
		}
		fill(ans,acc,0,fathers,s);
		return ans;
    }
    
    void fill(vector<string>& ans, string& acc, int index, map<int,vector<int> >& f, const string& s)
    {
    	if(index == s.size())
    	{
    		acc.pop_back();
    		ans.push_back(acc);
    		acc.push_back(' ');
    		return;
		}
		vector<int>& fathers = f[index];
		for(int i = 0;i < fathers.size(); i++)
		{
			int l = fathers[i]-index;
			acc.append(s.substr(index,l));
			acc.push_back(' ');
			fill(ans,acc,fathers[i],f,s);
			while(l--)acc.pop_back();
			acc.pop_back();
		}
	}
};
