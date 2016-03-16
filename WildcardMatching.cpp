#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Phases
{
public:
    	bool fin ;
    	bool nul ;
    	bool uni ;
    	bool cyc ;
    	char  cha;
    	Phases(char a)
    	{
    		if(a == -1)
			{
				fin = false;
				nul = false;
				uni = true;
				cyc = false;
    	    }
    	    else if(a == -3)
				fin = true;
    	    else if(a == -2)
    	    {
    	    	fin = false;
				nul = true;
				uni = true;
				cyc = true;	
			}
			else
    	    {
    	    	fin = false;
    			nul = false;
    			uni = false;
    			cha = a;
    			cyc = false;
    	    }
    	}
    	
    	void getMul()
    	{
    		nul = true;
    		cyc = true;
    	}
    	
    };
class Solution {
public:
    bool isMatch(string s, string p) 
	{
        vector<Phases>automa;
        phase(p,automa);
        return match(s,automa);
    }
    
    void phase(string p, vector<Phases>&automa)
    {
    	
    	
    	for(int i =0;i<p.size();i++)
    	{
    		if(p[i]=='?')
			automa.push_back(Phases(-1));
			else if(p[i]=='*')
			automa.push_back(Phases(-2));
			else automa.push_back(Phases(p[i]));
    	}
    	automa.push_back(Phases(-3));
    }
    
    bool match(string s, const vector<Phases>&automa)
    {
    	/*初始化状态集*/
    	bool statset [automa.size()];
    	for(int i =1; i < automa.size();i++)
    	statset[i]=false;
    	/*将初始状态加入状态集*/
    	statset[0]=true;
    	/*求初始状态集的ε闭包*/
    	for(int i = 0 ;i<automa.size();i++)
    	{
    		if(statset[i] && !automa[i].fin)
    		{
    			if(automa[i].nul)
    			statset[i+1]=true;
    		}
    	}
    	/*开始匹配字符串*/
    	for(int j = 0; j < s.size(); j++)
    	{
    		/*初始化新状态集*/
           	bool statup[automa.size()];
           	for(int i = 0 ;i<automa.size();i++)
           		statup[i] = false;
    		for(int i = 0 ;i<automa.size();i++)
    		{
    			/*状态集中的各个状态在字符串的作用下生成的新状态加入新状态集*/
    			if(statset[i]&&!automa[i].fin)
				{
					if(automa[i].uni)
					{
						statup[i+1]=true;
						if(automa[i].cyc)	statup[i]=true;
					}
					else
					{
						if(s[j]==automa[i].cha)
						{
							statup[i+1]=true;
							if(automa[i].cyc)	statup[i]=true;
						}
						
					}
    			}
    		}
    		/*用新状态集替换旧状态集*/
    		for(int i = 0 ;i<automa.size();i++)
    		{
    			statset[i] =false;
    			statset[i]= statup[i];
    		}
    		/*求状态集的ε闭包*/	
    		for(int i = 0 ;i<automa.size();i++)
    		{
    			if(statset[i]&&!automa[i].fin)
    			{
    				if(automa[i].nul)
    					statset[i+1]=true;
    			}
    		}	
    	}
    	return statset[automa.size()-1];	
    }

};

int main()
{
	Solution so;
	cout<<(so.isMatch("aaa","*")?"true":"false");
}
