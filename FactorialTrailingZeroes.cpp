#include<iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) 
	{
		int acc = 0;
        long long mul = 5;
        while(n/mul != 0)
        {
        	acc += (n/mul);
        	mul *= 5;
		}
		return acc;
    }
};

int main()
{
	Solution so;
	cout<<so.trailingZeroes(2147483646);
}
