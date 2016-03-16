#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) 
	{
		bool isTested[1500][1000];
	
		for(int i = 0 ; i <= s.size(); i++)
			for(int j = 0 ;j <= p.size(); j++)
				isTested[i][j]= false;		
        isMatch(s,0,p,0,isTested);
    }
    
    bool isMatch(string& s, int si, string& p, int pi,bool isTested[1500][1000])
    {
    	if(si == s.size()&& pi == p.size())return true;
    	if(si == s.size()^ pi == p.size())
		{
			isTested[si][pi]=true;
			return false;
		}
    	if(p[pi] =='?')
		{
			if(!isTested[si+1][pi+1])
			{
				if(isMatch(s,si+1,p,pi+1,isTested))
					return true;
			}
		}
    	else if(p[pi] =='*')
    	{
    		int i = si;
    		int j = pi+1;
    		while(j < p.size())
    		{
    			if(p[j] == '*')j++;
    			else break;
			}
    		while(i <= s.size())
    		{
				if(isTested[i][j])i++;
				else if(isMatch(s,i,p,j,isTested))
					return true;
			}
		}
		else if(p[pi] == s[si])
		{
			if(!isTested[si+1][pi+1])
			{
			  if(isMatch(s,si+1,p,pi+1,isTested))
			  	return true;
			}
		}
			isTested[si][pi] = true;
			return false;
	}
};

int main()
{
	Solution so;
	string s( "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb");
	string p("**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb");
	if(so.isMatch(s,p))cout<<"true";
	else cout<<"false";
}
