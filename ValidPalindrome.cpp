#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) 
    {
        int i = 0;
        int j = s.size()-1;
        while(i <= j)
        {
        	while(i <= j&&!isValid(s[i]))i++;
        	while(i <= j&&!isValid(s[j]))j--;
        	if(i > j)break;
        	if(lowercase(s[i]) != lowercase(s[j]))return false;
        	i++;
			j--;
		}
		return true;
    }
    
    bool isValid(char c)
    {
    	if((c >='0'&& c<='9')||(c >= 'a'&& c <='z')||(c >= 'A'&& c <= 'Z'))return true;
    	return false;
	}
	
	char lowercase(char c)
	{
		if(c >= 'A'&& c <= 'Z')return c-('A'-'a');
		return c;
	}
};
