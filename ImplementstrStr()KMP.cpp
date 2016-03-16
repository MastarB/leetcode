#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
    	if(needle.empty())return 0;
    	int pai[needle.size()];
    	// -1 means string neddle[0:k] cannot prefix match any string of {neddle[0:i](i = 1 to k-1)}
		int k = -1;
		pai[0] = -1;
		
		for(int i = 1;i<needle.size();i++)
		{
			while (k>=0 && needle[k+1] != needle[i])
				k = pai[k];
			if(needle[k+1] == needle[i])
				k++;
			pai[i]=k;
		}
		// i :index of haystack, j : index of needle.
		int j = -1;
		for(int i = 0 ; i<haystack.size();i++)
		{
			while(j >=0 && needle[j+1] != haystack[i])
				j = pai[j];
			if(needle[j+1] == haystack[i])
				j++;
			if(j == needle.size()-1)
			return i-j;
			//j = pai[j]; look for the next match.
		}
		return -1;
    }
};

int main()
{
	string a("abc");
	string b("bc");
	Solution so;
	cout<<so.strStr(a,b);
}
