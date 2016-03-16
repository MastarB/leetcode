#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    int calculate(string s) 
	{
        stack<char> stkOp;
        stack<int> stkNum;
        //0 in stkNum and '+' in stkOp will protect the num and operator below them and calculate in a new level
        stkOp.push('+');
        stkNum.push(0);
        int acc = 0;
        char lastChritmas;
        for(int i = 0; i < s.size(); ++i)
        {
        	
        	if(s[i] >= '0' && s[i] <= '9')
			{
				acc *= 10;
				acc += s[i]-'0';	
			}
			else if(s[i] == '(')
			{
				stkNum.push(0);
				stkOp.push('+');
			}
			else if(s[i] == ')')
			{
				int a = stkNum.top();
				acc = getAns(a,acc,stkOp.top());
				stkNum.pop();
				stkOp.pop();		
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				int a = stkNum.top();
				int ans = getAns(a,acc,stkOp.top());
				acc = 0;
				stkNum.pop();
				stkOp.pop();
				stkOp.push(s[i]);
				stkNum.push(ans);
			}
			else
			{
				//do nothing!
			}
		}	
		return getAns(stkNum.top(),acc,stkOp.top());
		
		
    }
    int getAns(int a, int b, char op)
    {
    	switch(op)
    	{
    		case '+':
    			return a+b;
    		case '-':
    			return a-b;
		}
	}
};

int main()
{
	Solution so;
	string s("(1+(4+5+2)-3)+(6+8)");
	cout<<so.calculate(s);
}
