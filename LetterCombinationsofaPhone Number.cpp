#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
    	vector<string> ans;
        int index =0;
        string buffer ="";
        print (buffer,digits,0,ans);
        return ans;
    }
    void print(string& buffer, string& digits, int index, vector<string>& ans)
    {
    	if(index >= digits.size())
    	{
    		if(buffer.compare("") != 0)
    			ans.push_back(buffer);
		}
		else
		{
			switch(digits[index])
			{
				case '2':
					buffer.push_back('a');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('b');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('c');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					break;
				case '3':
					buffer.push_back('d');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('e');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('f');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					break;
				case '4':
					buffer.push_back('g');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('h');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('i');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					break;
				case '5':
					buffer.push_back('j');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('k');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('l');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					break;
				case '6':
					buffer.push_back('m');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('n');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('o');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					break;
				case '7':
					buffer.push_back('p');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('q');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('r');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('s');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					break;
				case '8':
					buffer.push_back('t');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('u');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('v');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					break;
				case '9':
					buffer.push_back('w');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('x');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('y');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					buffer.push_back('z');
					print(buffer,digits,index+1,ans);
					buffer.pop_back();
					break;
					
			}
		}
	}
};

int main()
{
	Solution so;
	vector<string>ans = so.letterCombinations("2223");
	for(int i = 0; i<ans.size(); i++)
		cout<<ans[i]<<endl; 
	cout<<ans.size();

	 
}
