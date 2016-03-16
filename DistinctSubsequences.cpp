#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) 
    {
    	
    	int s_l = s.size();
    	int t_l = t.size();
    	int tab[s_l+1][t_l+1];
    	for(int j = 1; j <= t_l; j++)
    		tab[0][j] = 0;
        for(int i = 0; i <= s_l; i++)
         	tab[i][0] = 1;
        for(int i = 1; i <= s_l; i++)
        	for(int j = 1; j <= t_l; j++)
        		tab[i][j] = s[i-1]==t[j-1] ? tab[i-1][j]+tab[i-1][j-1]:tab[i-1][j];
        		
        /*	for(int i = 0; i <= s_l; i++)
			{
				for(int j = 0; j <= t_l; j++)
					cout<<tab[i][j]<<' ';
				cout<<endl;
			}
		*/		
				
        return tab[s_l][t_l];
        
    }
};

int main()
{
	Solution so;
	string s("ddd");
	string t("dd");
	cout<<so.numDistinct(s,t);
}
