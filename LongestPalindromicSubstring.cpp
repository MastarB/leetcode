#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
    	int max =0 ;
    	int bg,ed;
    	int xbg=0,xed=0;
    	int k,j,max1;
		if(!s.empty())max =1;
 		for(int i  = 0; i < s.size(); i++)
		{
			 k=i;
			 j=i+1;
			 max1 =0;
			while(k>=0&&j<s.size())
			{
				if(s[k] == s[j])
				{
					max1 += 2;
					bg = k;
					ed = j;
					k--;
					j++;
				}
				else break;
			}
			if(max1 > max)
			{
				max = max1;
				xbg = bg;
				xed = ed;
				
			}
			 k = i-1;
			 j = i+1;
			max1 = 1 ;
			while(k >= 0 && j < s.size())
			{
				if(s[k] == s[j])
				{
					max1 += 2;
					bg = k;
					ed = j;
					k--;
					j++;
					
				}
				else break;
			}
			if(max1 > max)
			{
				max = max1;
				xbg = bg;
				xed = ed;
				
			}
		}
		return   s.substr(xbg,xed-xbg+1);     
    }
};

int main()
{
	Solution so;
	string s("12345123451234512345");
	for(int i=0; i <100;i++)
		s.append("12345123451234512345");
	cout<<so.longestPalindrome(s);
}
