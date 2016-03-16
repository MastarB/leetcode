#include<stack>
#include<string>
using namespace std;

class Solution 
{
public:
    bool isValid(string s) 
	{
    	stack<char>vali;
    	for(int i = 0 ; i < s.size();i++)
    	{
    		if(s[i] =='('||s[i] =='{'||s[i] =='[')
    		vali.push(s[i]);
    		else if(s[i] ==')'||s[i] ==']'||s[i] =='}')
    		{
    		    if(vali.empty())return false;
    			if(vali.top()==s[i]-1||vali.top()==s[i]-2)
    			vali.pop();
    			else vali.push(s[i]);
			}
		}
		return vali.empty();
			    
    }
};
int main()
{
	
}
