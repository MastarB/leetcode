#include<unordered_map>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
	{
		
		vector<string>ans;
		unordered_map<int,bool>set;
		if(s.size() < 10)return ans;
		string init(s.substr(0,10));
		int k = 0;
		for(int i = 0; i < s.size();i++)
		{
			k <<= 2;
			switch(s[i])
			{
				case 'A':
					k++;
				case 'T':
					k++;
				case 'G':
					k++;
				case 'C':
					;
			}
			
			if(i >= 9)
			{
				k &= 0x000FFFFF;
				if(set.find(k) == set.end())set[k] = false;
				else if(!set[k])
				{
					ans.emplace_back(s.substr(i-9,10));
					set[k] = true;
				}
			}
		}
		return ans;     
    }  
};

int main()
{
	Solution so;
	string s("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	vector<string>a(so.findRepeatedDnaSequences(s));
	for(string t : a)
	cout<<t<<endl;
	
}

