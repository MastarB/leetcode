class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n == 0)return x/x;
		else if(n < 0)return 1/myPow(x,-n);
		else
		{
			double a(1.0);
			for(int i = 0; i < n; i++)
				a*=x;
			return a;
		} 
    }
};
