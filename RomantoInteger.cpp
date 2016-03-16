#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s)
	{
		int ans = 0;
    	bool minus3 = false;
    	bool minus2 = false;
    	bool minus1 = false;
    	char minusc;
    	for(int i = 0 ;i<s.size();i++)
		{
			switch(s[i])
			{
				case 'M':
					if(minus3)
					ans+=800;
					else ans +=1000;
					minus3 = false;
					break;
				case 'D':
					if(minus3)
					ans+=300;
					else ans+=500;
					minus3 = false;
					break;
				case 'C':
					if(minus2)
					ans +=80;
					else 
					{
						ans +=100;
						minus3 = true;
					}
					minus2 =false;
					break;
				case 'L':
					if(minus2)
					ans +=30;
					else ans+=50;
					minus2 =false;
					break;
				case 'X':
					if(minus1)
					ans += 8;
					else
					{
						ans +=10;
						minus2 =true;
					}
					minus1 = false;
					break;
				case 'V':
					if(minus1)
				    	ans += 3;
				    else
				    	ans +=5;
				    minus1 =false;
				    break;
				case 'I':
					ans+=1;
					minus1 = true;
					 break;
			}
			
		}
		return ans;
		
				
        
    }
};

int main()
{
	string a("MMMCMXCIX");
	Solution so;
	cout<<so.romanToInt(a);
}
