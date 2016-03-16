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
    	/*��ʼ��״̬��*/
    	bool statset [automa.size()];
    	for(int i =1; i < automa.size();i++)
    	statset[i]=false;
    	/*����ʼ״̬����״̬��*/
    	statset[0]=true;
    	/*���ʼ״̬���Ħűհ�*/
    	for(int i = 0 ;i<automa.size();i++)
    	{
    		if(statset[i] && !automa[i].fin)
    		{
    			if(automa[i].nul)
    			statset[i+1]=true;
    		}
    	}
    	/*��ʼƥ���ַ���*/
    	for(int j = 0; j < s.size(); j++)
    	{
    		/*��ʼ����״̬��*/
           	bool statup[automa.size()];
           	for(int i = 0 ;i<automa.size();i++)
           		statup[i] = false;
    		for(int i = 0 ;i<automa.size();i++)
    		{
    			/*״̬���еĸ���״̬���ַ��������������ɵ���״̬������״̬��*/
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
    		/*����״̬���滻��״̬��*/
    		for(int i = 0 ;i<automa.size();i++)
    		{
    			statset[i] =false;
    			statset[i]= statup[i];
    		}
    		/*��״̬���Ħűհ�*/	
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
