#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) 
	{
		
		long long nn(n-1);
		string s("");
		long long mul = 1;
		long long acc = 0;
		 
        while(nn-acc-mul*26 >= 0)
        {
			acc += mul*26;
			mul *= 26;
		}
		nn -= acc;
		while(mul != 0)
		{
			s.push_back(nn/mul%26+'A');
			mul /= 26;	
		}
		return s;
    }
};

int main()
{
	int a = 26;
	Solution so;
	cout<<so.convertToTitle(a);
}
