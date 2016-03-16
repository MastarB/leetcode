#include<queue>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) 
	{
    	vector<vector<string>>ans;
		unorder_set<string>orgi;
		orgi.insert(beginWord);
		vector<string>acc;
		fill(ans,acc,orgi,wordList,endWord);
		return ans;    
    }
    
    void fill(vector<vector<string>>& ans, vector<string>& acc,unordered_set<string>& orgi, unordered_set<string> &wordList, const string& endWord)
    {
    	bool geted = false
    	for(iterator::unordered_set<string> i = orgi.begin(); i != orgi.end(); i++)
    	{
    		if(dyoc(*i,endWord))
    		{
    			geted = true;
    			acc.push_back(*i);
    			acc.push_back(endWord);
    			ans.push_back(acc);
    			acc.pop_back();
    			acc.pop_back();
			}
		}
		if(geted)return;
    	unordered_set<string>thislevel;
    	for(iterator::unordered_set<string> i = orgi.begin(); i != orgi.end(); i++)
    	{
    		for(iterator::unordered_set<string> j = wordList.begin(); j != wordList.end(); j++)
    			if(dyoc(*i,*j))thislevel.insert(*i);
		}
		for(iterator::unordered_set<string> i = thislevel.begin(); i != thislevel.end(); i++)
			wordList.erase(*i);
		for(iterator::unordered_set<string> i = orgi.begin(); i != orgi.end(); i++)
		{
			
		}
	}
    bool dboc(const string& a, const string& b)
    {
    	int l = a.size();
    	bool dboc = false;
    	for(int i = 0; i < l; i++)
    	{
    		if(a[i] != b[i])
    		{
    			if(dboc)return false;
    			dboc = true;
			}
		}
		return true;
	} 
};
