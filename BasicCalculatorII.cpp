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
				/*
					while(prio(stkOp.top())>= prio(s[i]))
					{
						bool flag = false;
						if(prio(stkOp.top()) != prio(s[i]))
						 	flag = true;
						 	
						a = stkNum.top();
						ans = getAns(a,ans,stkOp.top());
						stkNum.pop();
						stkOp.pop();
						
						if(flag)
							break;
					}
					*/
				if(stkOp.top() == '*'||stkOp.top() == '/')
				{
					acc = getAns(stkNum.top(),acc,stkOp.top());
					stkNum.pop();
					stkOp.pop();
				}
				int ans = getAns(stkNum.top(),acc,stkOp.top());
				acc = 0;
				stkNum.pop();
				stkOp.pop();
				stkOp.push(s[i]);
				stkNum.push(ans);
			}
			
			else if (s[i] == '*' || s[i] == '/')
			{
				if(stkOp.top() != '*'&&stkOp.top()!='/')
				{
					stkNum.push(acc);
					stkOp.push(s[i]);
					acc = 0; 
				}
				else
				{
					int a = stkNum.top();
					int ans = getAns(a,acc,stkOp.top());
					acc = 0;
					stkNum.pop();
					stkOp.pop();
					stkNum.push(ans);
					stkOp.push(s[i]);
					
				}
			}
			else
			{
				//do nothing!
			}
			
			//cout<<stkNum.top()<<' '<<stkOp.top()<<endl;
		}
		int ans = acc; 
		while(!stkNum.empty())
		{
			
			ans = getAns(stkNum.top(),ans,stkOp.top());
			stkNum.pop();
			stkOp.pop();
		}	
		return ans;
		
		
    }
    int getAns(int a, int b, char op)
    {
    	switch(op)
    	{
    		case '+':
    			return a+b;
    		case '-':
    			return a-b;
    		case '*':
    			return a*b;
    		case '/':
    			return a/b;
		}
	}
};

int main()
{
	Solution so;
	string s("2*(1+3)-3");
	cout<<so.calculate(s);
}
