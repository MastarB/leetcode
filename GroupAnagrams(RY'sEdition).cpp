#include<string>
#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
    	vector<vector<string>> ans;
    	vector<pair<string,string> >alllist;
    	for(int i = 0; i < strs.size(); i++)
    	{
    		string s(strs[i]);
    		sort(s,0,s.size()-1);
    		alllist.push_back(make_pair(s,strs[i]));
		}
		sort(alllist,0,alllist.size()-1);
		vector<string>acc;
		if(alllist.size() == 0)
		{
			ans.push_back(acc);
			return ans;
		}
		else
		{
			string guard = alllist[0].first;
			acc.push_back(alllist[0].second);
			for(int i = 1; i < alllist.size(); i++)
			{
				if(alllist[i].first == guard)acc.push_back(alllist[i].second);
				else
				{
					guard = alllist[i].first;
					ans.push_back(acc);
					acc.clear();
					acc.push_back(alllist[i].second);
				}
			}
			ans.push_back(acc);
		}
		return ans;
    }
    //sorting for strings
   	void sort(string& v,int b, int e)
   	{
   		if(b < e)
   		{
   			int p = partition(v,b,e);
   			sort(v,b,p-1);
   			sort(v,p+1,e);
		}
	}
	
	int partition(string& v,int b, int e)
	{
		int i = b+1;
		int j = e;
		while(i <= j)
		{
			if(v[i] > v[b])
			{
				swap(v[i],v[j]);
				j--;
			}
			else i++;
		}
		swap(v[b],v[i-1]);
		return i-1;
	}
	//sorting for string pairs
	void sort(vector<pair<string,string> >& v, int b, int e)
	{
		if(b < e)
   		{
   			int p = partition(v,b,e);
   			sort(v,b,p-1);
   			sort(v,p+1,e);
		}
	}
	
	int partition(vector<pair<string,string> >& v,int b, int e)
	{
		int i = b+1;
		int j = e;
		while(i <= j)
		{
			if(v[i].first.compare(v[b].first) > 0||v[i].second.compare(v[b].second)>0 && !v[i].first.compare(v[b].first))
			{
				swap(v[i],v[j]);
				j--;
			}
			else i++;
		}
		swap(v[b],v[i-1]);
		return i-1;
	}
	
};
