#include<iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
    	int i=0;
    	bool pos = true;
    	bool sign = false;
    	long long ans = 0;
    	while(str[i]==' '||str[i]=='"')
    		i++;
    	while(str[i]=='+'||str[i]=='-')
    	{
    		if(sign)return 0;
    		pos = str[i]=='-'?false:true;
    		sign = true;
    		i++;
    	}
    	for(;i<str.size();i++)
    	{
    		if(str[i]>='0'&&str[i]<='9')
    		{
    			if(pos&&ans>=2147483648||!pos&&ans>2147483648)break;
    			ans*= 10;
    			ans +=(str[i]-'0');
    		}
    		else break;
			
    	}
    	if(pos&&ans>=2147483648||!pos&&ans>2147483648)
			return pos?2147483647:-2147483648;
			
		else return pos?ans:-ans; 
    	
    }
};

int main()
{
	Solution so;
	cout<<so.myAtoi("9223372036854775809");
	
}
