#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	string s;
    	if(x < 0)
    		return false;
    	while (x)
    	{
    		s.push_back('0'+x%10);
    		x/=10;
    	}
    	for(int i = 0,j = s.size()-1; i<s.size();i++,j--)
    	if(s[i] != s[j])return false;
		return true; 
    }
};

int main()
{
	Solution so;
	cout<<so.isPalindrome(12334321);
}
