#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) 
    {
    	int bits = s.size();
    	int acc = 1;
    	int mul = 1;
    	//assert that the size of "s" is greater than 1
    	for(size_t i = 0; i < s.size()-1; i++)
    	{
    		acc += (mul*26);
    		mul *= 26;
		}
		for(size_t i = 0; i < s.size(); i++)
		{
			acc += (s[i]-'A')*mul;
			mul /= 26;
		}
		return acc;
    }
};

int main()
{
	string s("Z");
	Solution so;
	cout<<so.titleToNumber(s);
}
