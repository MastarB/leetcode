#include<iostream>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) 
    {
    	int ans = 0;
    	int c = 0x40000000;
    	for(int i = 0; i < 31; i++,c>>=1)
		{
				if((m&c) == (n&c))//priority of bit operation is very low!!
					ans |= (m&c);
				else return ans;
		}
		return ans;
    }
};

int main()
{
	Solution so;
	std::cout<<so.rangeBitwiseAnd(1,1);
}
