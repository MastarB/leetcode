#include<map>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxl = 0;
        int begin = 0;
    	map<char,int>index;
    	
    	for(int i = 0; i < s.size(); i++)
    	{
    		if(index.find(s[i]) != index.end())
    		{	
				for(int j = begin; j != index[s[i]]; j++)
				index.erase(s[j]);
				begin =index[s[i]]+1;
			}
			index[s[i]]=i;
			maxl = max(maxl,i-begin+1);
    	
        }
        return maxl;
    }
};

int main()
{
Solution b;
	string a;
	while(cin>>a)
	
	cout<<b.lengthOfLongestSubstring(a);
}
