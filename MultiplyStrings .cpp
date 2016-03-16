#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) 
    {
    	 	
            string a("0");
            for(int i = num1.size()-1 ;i >= 0; i--)
            {
            	if(num1[i] == '0')continue;
            	string b;
            	int carry = 0;
            	
            	for(int j = num2.size()-1; j >=0; j--)
            	{
					int ans = (num1[i]-'0')*(num2[j]-'0')+carry; 
					carry = ans/10;
					b.push_back(ans%10+'0');
				}
				while(carry)
				{
					b.push_back(carry%10+'0');
					carry /= 10;
				}
				if(b[b.size()-1] =='0')continue;
				for(int k = 0; k < num1.size()-i-1; k++)
					b.insert(b.begin(),'0');	
				add(a,b);
			}
			for(int i = 0 ;i < a.size()/2; i++)
				swap(a[i],a[a.size()-i-1]);
			return a;
    }
    
    void add(string& a, string& b)
    {
    	cout<<a<<' '<<b<<endl;
    	int i =0;
    	int carry = 0;
    	
    	while(i < a.size()&&i < b.size())
    	{
    		int ans = carry+(a[i]-'0')+(b[i]-'0');
    		a[i] = ans%10 + '0';
    		carry = ans/10;
    		i++;
		}
		while(carry || i < a.size() || i < b.size())
		{
			int ans;
				if(i < a.size())
				{
					ans = carry+a[i]-'0';
					a[i] = ans%10 + '0';
					carry = ans/10;
    			
    			}
				else if(i < b.size())
				{
					ans= carry+b[i]-'0';
    				a.push_back(ans%10 + '0');
    				carry = ans/10;
    			}
    			else
    			{
    				a.push_back(carry%10+'0');
    				carry /= 10;
				}
			i++;
		}
	}
};

int main()
{
	string a("9133");
	string b("0");
	Solution so;
	cout<<so.multiply(a,b);
}
