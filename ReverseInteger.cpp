#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        bool positive =true;
        if( x < 0 )
        {
            x =-x;
            positive =false;
        }
        int ans=0;
        while(x!=0)
        {
            if(ans*10/10 == ans)ans*=10;
            else return 0;
            ans+=(x%10);
            x/=10;
        }
        return positive?ans:-ans;
    }
};

int main()
{
	Solution so;
	cout<<so.reverse(1534236469);
}
