#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
	{
		string comPre;
		int min = 0;
		bool fin =false;
    	for(int i = 0; i< strs.size(); i++)
    		min = min < strs[i].size()?strs[i].size():min;
    	for(int i = 0; i<min; i++)
		{
			char same =strs[0][i];
			for(int j = 1;j < strs.size(); j++)
			{
				if(same !=strs[j][i])
				{
					fin =true;
					break;
				}
			}
			if(fin)break;
			else comPre.push_back(same);
		}
		return comPre;	
    }
};

int main()
{
	vector<string>strs;
	strs.push_back("aa");
	strs.push_back("aa");
	strs.push_back("aa");
	strs.push_back("ab");
	Solution so;
	cout<<so.longestCommonPrefix(strs);
}
