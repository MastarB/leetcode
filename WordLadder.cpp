#include<string>
#include<unordered_set>
#include<queue>
#include<iostream>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) 
	{
		if(!beginWord.compare(endWord))return 1;
		int step = 2;
        int l = wordList.size();
        queue<string>former;
        former.push(beginWord);
        while(!former.empty())
        {
        	int s = former.size();
        	for(int n = 0; n < s; n++)
        	{
        		if(difByOne(former.front(),endWord))return step;
        		else
        		for(unordered_set<string>::iterator i = wordList.begin(); i != wordList.end();)
        		{
        			
        			if(difByOne(*i,former.front()))
        			{
        				former.push(*i);
        				i = wordList.erase(i);
					}
					else i++;
				}
				former.pop();
			}
			step++;
		}
		return 0;
    }
    
    /* string a and b are different*/
    bool difByOne(const string& a, const string& b)
    {
    	bool oneDif= false;
    	for(int i = 0; i < a.size(); i++)
    	{
    		if(a[i] != b[i])
    		{
    			if(!oneDif)oneDif = true;
    			else return false;
			}
		}
		return true;
	}
};

int main()
{
	char c[5][10]= {"hot","dot","dog","lot","log"};
	string a("hit");
	string b("cog");
	Solution so;
	
	unordered_set<string>wordlist;
	for(int i = 0; i < 5; i++)
		wordlist.insert(string(c[i]));
	cout<<so.ladderLength(a,b,wordlist);
}
