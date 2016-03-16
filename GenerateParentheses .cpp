#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string>ans;
        string buffer = "";
        put(ans,buffer,n,0);
        return ans;
    }
    /* 	variable "nleft" represents the maximum number of '(' which can be added at the back of 'buffer' currently
		variable "nright" represents the maximum number of ')' which can be added at the back of 'buffer' currently 
	*/
    void put(vector<string>& ans, string& buffer, int nleft, int nright)
    {
    	if(nleft == 0 && nright ==0)
    	{
    		ans.push_back(buffer);
    		return;
		}
    	if(nleft > 0)
		{		
    		buffer.push_back('(');
    		put(ans,buffer,nleft-1,nright+1);
    		buffer.pop_back();
    	}
    	if(nright > 0)
    	{
    		buffer.push_back(')');
    		put(ans,buffer,nleft,nright-1);
    		buffer.pop_back();
		}
	}
};

int main()
{
	
}
