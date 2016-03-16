#include<cmath>
#include<iostream>
#define MAX_INT 2147483647 
#define MIN_INT -2147483648 
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) 
    {	
		if(divisor == MIN_INT)
		{
			if(dividend != MIN_INT)return 0;
			return 1;
		}
		if(divisor ==-1 &&dividend ==MIN_INT)return MAX_INT;
    	bool get1 =false;
    	bool pos = true;
    	if(dividend < 0)
    	{
    		if(dividend == MIN_INT)
    		{
    			dividend ++;
    			get1 = true;
			}
    		pos = false;
    		dividend = -dividend;
    	}
    	if(divisor < 0)
    	{
    		if(pos)pos = false;
    		else pos = true;
    		divisor = -divisor;
		}
    	int n = 0;
    	int ndivisor = divisor;
    	int multi = 1;
    	int formerdi;
    	int formermul;
        while(dividend >= ndivisor&&ndivisor > 0)
        {
        	formerdi =  ndivisor;
        	formermul = multi;
			dividend -= ndivisor;
			n+=multi;
			ndivisor +=ndivisor;
			multi +=multi;
    	}
    	ndivisor = formerdi;
    	multi = formermul;
    	if(get1)dividend ++;
    	while(dividend >= divisor)
		{
			if(dividend <ndivisor)
			{
				ndivisor = ndivisor>>1;
				multi = multi>>1;
			}
			else
			{
				dividend -= ndivisor;
				n += multi;
			}
		}
    	return pos?n : -n;
	}	
};

int main()
{
	Solution so;
	cout<<so.divide(MIN_INT,-1109186033);
}
